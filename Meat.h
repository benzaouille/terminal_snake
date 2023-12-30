#ifndef MEAT_H
#define MEAT_H
////////////////////////////////////////////////////////////////////////////////
#include <random>
////////////////////////////////////////////////////////////////////////////////
#include "Frame.h"

class Meat
{
  public:
    Meat();

    Meat(Frame& frame);

    void randmonSamplingMeat();

    void get_meat_pos(float& m_x, float& m_y) const;

    void draw(Frame& frame);

    void updatePos(Frame& frame);
  private:
    std::mt19937 rng;
    std::uniform_int_distribution<int> dist_x;
    std::uniform_int_distribution<int> dist_y;
    float m_x;
    float m_y;
};

#endif //#ifndef MEAT_H
