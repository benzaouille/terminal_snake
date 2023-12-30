////////////////////////////////////////////////////////////////////////////////
#include <chrono>
#include <thread>
#include <future>
#include <iostream>
////////////////////////////////////////////////////////////////////////////////
#include "utils.h"
#include "Frame.h"
#include "Keyboard_Handle.h"
#include "Snake.h"
#include "Meat.h"
////////////////////////////////////////////////////////////////////////////////


using namespace std;

int main() {
    //set up the frame that will be drawn using ncurses
    const chrono::milliseconds timeOut = chrono::milliseconds(50);
    Frame frame(timeOut);
    frame.fillFrame('a');
    frame.fillSquareFrame('|');
    frame.drawFrame();

    //keyboard handling
    Keyboard_Handle kH(timeOut);
    thread keybord_th(ref(kH));
    keybord_th.detach();

    //Meat initialization
    Meat meat(frame);

    //Snake initialization
    Snake head(0, 0, meat);
    head.addBody();
    head.execute(DIR::NOTHING, frame);

    int i = 0;
    while(true)
    {
      int ch = 0;
      bool isSet = false;
      while(kH.keypress(ch, isSet)){}
      if(isSet && ch == 'q'){break;}
      else if(isSet && ch == KEY_LEFT){head.execute(DIR::LEFT, frame);}
      else if(isSet && ch == KEY_RIGHT){head.execute(DIR::RIGHT, frame);}
      else if(isSet && ch == KEY_UP){head.execute(DIR::UP, frame);}
      else if(isSet && ch == KEY_DOWN){head.execute(DIR::DOWN, frame);}



      frame.drawFrame();
      this_thread::sleep_for(timeOut);
    }
    
    endwin();
    return 0;
}
