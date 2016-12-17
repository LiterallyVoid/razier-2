/* -*- mode: c++ -*- */

#ifndef _SHIP_H
#define _SHIP_H

#include <Box2D/Box2D.h>

#define SHIP_YAW_LEFT (1 << 0)
#define SHIP_YAW_RIGHT (1 << 1)
#define SHIP_ACCELERATE (1 << 2)
#define SHIP_REVERSE (1 << 3)

class Ship {
public:
    Ship(b2World *world);
    ~Ship();

    void Control(int controls);
    void Step();
    void Draw();

private:
    b2Body *body;
    int controls;
};

#endif // _SHIP_H
