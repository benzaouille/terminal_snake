#ifndef FRAME_H
#define FRAME_H
////////////////////////////////////////////////////////////////////////////////
#include <chrono>
#include <thread>
#include <iostream>
////////////////////////////////////////////////////////////////////////////////
#include <ncurses.h>

class Frame
{
  public:
      Frame(const std::chrono::milliseconds& timeOut);

      Frame(unsigned short width, unsigned short height);

      ~Frame();

      void fillFrame(char cha);

      void fillFrame_at_XY(float x, float y);

      void fillBuffer_at_XY(float x, float y, char ch);

      void drawFrame();

      void fillSquareFrame(char ch);

      void clearScreen();

      unsigned short get_screen_width() const ;

      unsigned short get_screen_height() const ;

  private:
    char* m_buffer = nullptr;
    size_t m_size_buffer;
    unsigned short m_width = 0;
    unsigned short m_height = 0;
    unsigned short m_game_width = 0;
    unsigned short m_game_height = 0;
    std::chrono::milliseconds m_timeOut;

};

#endif //FRAME_H
