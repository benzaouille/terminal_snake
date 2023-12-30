#include "Frame.h"


Frame::Frame(const std::chrono::milliseconds& timeOut) : m_timeOut(timeOut),
m_game_height(10), m_game_width(20)
{
  //Start ncurses mode
  initscr();
  keypad(stdscr, TRUE);
  mousemask(ALL_MOUSE_EVENTS, NULL);
  getmaxyx(stdscr, m_height, m_width);

  m_size_buffer = m_height * m_width;
  m_buffer = new char[m_height * m_width];
  fillFrame('t');
}

Frame::Frame(unsigned short width, unsigned short height):
m_width(width), m_height(height), m_game_height(30), m_game_width(20)
{
  //Start ncurses mode
  initscr();
  keypad(stdscr, TRUE);
  mousemask(ALL_MOUSE_EVENTS, NULL);

  m_size_buffer = m_height * m_width;
  m_buffer = new char[m_height * m_width];
}


Frame::~Frame()
{
  delete m_buffer;
  //end the ncurses mode
  endwin();
}

//x,y = SCREEN_WIDTH-1, SCREEN_HEIGHT-1< --> B = SCREEN_HEIGHT*SCREEN_WIDTH-1
// Function that fill a frame with 'cha' at the position 'x' & 'y'
// x --> [O ; m_game_width-1]
// y --> [O ; m_game_height-1]
void Frame::fillFrame_at_XY(float x, float y)
{
  mvaddch(static_cast<int>(y + m_height/2.0f), static_cast<int>(x + m_width/2.0f),
          m_buffer[static_cast<int>(x + m_width/2.0f) *m_height + static_cast<int>(y + m_height/2.0f)]);
}

// x --> [O ; m_game_width-1]
// y --> [O ; m_game_height-1]
void Frame::fillBuffer_at_XY(float x, float y, char ch)
{
  m_buffer[static_cast<int>(x + m_width/2.0f) *m_height + static_cast<int>(y + m_height/2.0f)] = ch;
}

// Function that fill a frame with 'cha' everywhere
void Frame::fillFrame(char ch)
{
  for(unsigned short i = 0 ; i < m_size_buffer ; ++i)
  {
    m_buffer[i] = ch;
  }
}

// Function to draw a frame
void Frame::drawFrame()
{
  for(float y = -m_height/2.0f; y < m_height/2.0f ; ++y)
  {
    for(float x = -m_width/2.0f; x < m_width/2.0f ; ++x)
    {
        fillFrame_at_XY(x, y);
    }
  }
  std::this_thread::sleep_for(m_timeOut);
  refresh();
}

// Function to draw a frame
void Frame::fillSquareFrame(char ch) {
  for (unsigned short y = 0; y < m_game_height; ++y) {
        for (unsigned short x = 0; x < m_game_width; ++x) {
            if (y == 0 || y == m_game_height - 1 || x == 0 || x == m_game_width - 1) {
              m_buffer[(x + m_width/2 - m_game_width/2) *m_height + y + m_height/2 - m_game_height/2] = ch;
            }
            else{
              m_buffer[(x + m_width/2 - m_game_width/2) *m_height + y + m_height/2 - m_game_height/2] = ' ';
            }
        }
    }
}

// Function to clear the screen
void Frame::clearScreen() {
    refresh();
}

unsigned short Frame::get_screen_width() const
{
  return m_game_width;
}

unsigned short Frame::get_screen_height() const
{
  return m_game_height;
}
