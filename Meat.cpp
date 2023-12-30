#include "Meat.h"

Meat::Meat()
{}

Meat::Meat(Frame& frame)
{
  // Random number engine (Mersenne Twister in this example)
    rng = std::mt19937(std::random_device{}());
    dist_x = std::uniform_int_distribution<int>(std::ceil(-frame.get_screen_width() / 2), std::floor(frame.get_screen_width() / 2));
    dist_y = std::uniform_int_distribution<int>(std::ceil(-frame.get_screen_height() / 2), std::floor(frame.get_screen_height() / 2));

    randmonSamplingMeat();

    draw(frame);
}

void Meat::randmonSamplingMeat()
{
  m_x = dist_x(rng);
  m_y = dist_y(rng);
}


void Meat::get_meat_pos(float& x, float& y) const
{
  x = m_x;
  y = m_y;
}


void Meat::draw(Frame& frame)
{
  frame.fillBuffer_at_XY(m_x, m_y, 'm');
  frame.fillFrame_at_XY(m_x, m_y);
}

void Meat::updatePos(Frame& frame)
{
  frame.fillBuffer_at_XY(m_x, m_y, ' ');
  frame.fillFrame_at_XY(m_x, m_y);
  randmonSamplingMeat();
  draw(frame);
}
