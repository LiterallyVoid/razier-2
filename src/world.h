/* -*- mode: c++ -*- */

#ifndef _WORLD_H
#define _WORLD_H

#define WORLD_STEP_DELTA 0.015 // 66.6666667 framerate

#include <Box2D/Box2D.h>
#include <vector>

#include "ship.h"

class World {
public:
    World();
    ~World();

    Ship *CreateShip();
    void Step(double delta);
    void Draw();

private:
    b2World *world;
    b2Body *staticBody;

    double deltaAccumulation;

    std::vector<Ship*> ships;
};

#endif // _WORLD_H
