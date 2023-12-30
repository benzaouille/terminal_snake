#ifndef SNAKE_H
#define SNAKE_H
////////////////////////////////////////////////////////////////////////////////
#include<iostream>
////////////////////////////////////////////////////////////////////////////////
#include "Frame.h"
#include "utils.h"
#include "Meat.h"
////////////////////////////////////////////////////////////////////////////////

class Snake
{
  public:
    Snake(short x, short y, const Meat& meat);

    Snake(short x, short y);

    void addBody();

    void draw(Frame& frame, const char ch) const;

    void move(short x, short y);

    void move(const DIR dir);

    void execute(const DIR dir, Frame& frame);

  private:
    Meat m_meat;
    Snake* m_body = nullptr;
    short m_x = 0;
    short m_y = 0;
};

#endif //SNAKE_H
