#include "Snake.h"

Snake::Snake(short x, short y, const Meat& meat):
m_x(x), m_y(y), m_meat(meat)
{}
  

Snake::Snake(short x, short y):
m_x(x), m_y(y)
{}


void Snake::draw(Frame& frame, const char ch) const
{
  frame.fillBuffer_at_XY(m_x, m_y, ch);
  frame.fillFrame_at_XY(m_x, m_y);
  if(m_body != nullptr)
  {
    m_body->draw(frame, ch);
  }
}

void Snake::addBody()
{
  if(m_body == nullptr)
  {
    m_body = new Snake(m_x, m_y);
  }
  else
  {
    m_body->addBody();
  }
}


void Snake::move(short x, short y)
{
  if(m_body != nullptr)
  {
    m_body->move(m_x, m_y);
  }

  m_x = x;
  m_y = y;
}

void Snake::move(const DIR dir)
{
  move(m_x + dir_indirection[dir].first, m_y + dir_indirection[dir].second);
}

void Snake::execute(const DIR dir, Frame& frame)
{
  float meat_pos_x, meat_pos_y;
  m_meat.get_meat_pos(meat_pos_x, meat_pos_y);

  if(m_x == meat_pos_x && m_y == meat_pos_y)
  {
    m_meat.updatePos(frame);
    addBody();
  }


  draw(frame, ' ');
  move(dir);
  draw(frame, '*');
}
