#ifndef KEYBOARD_HANDLE
#define KEYBOARD_HANDLE
////////////////////////////////////////////////////////////////////////////////
#include <ncurses.h>
////////////////////////////////////////////////////////////////////////////////
#include <future>
#include <queue>


using namespace std;

class Keyboard_Handle
{
  public:
    Keyboard_Handle(const std::chrono::milliseconds& timeOut);

    void operator()();

    future<char> get_future_value();

    void set_promise();

    bool keypress(int& ch, bool& isSet) ;

  private:
    std::chrono::milliseconds m_timeOut;
    promise<char> m_promiseObj;
    std::queue<int> m_buffer_key;
};



#endif //KEYBOARD_HANDLE
