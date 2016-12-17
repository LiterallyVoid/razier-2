#include <GLFW/glfw3.h>

#include "world.h"

World::World() : world(new b2World(b2Vec2(0.0f, 0.0f))) {
};

World::~World() {
    delete world;
};

Ship *World::CreateShip() {
    Ship *ship = new Ship(world);
    ships.push_back(ship);
    return ship;
};

void World::Step(double delta) {
    deltaAccumulation += delta;
    while(deltaAccumulation > WORLD_STEP_DELTA) {
        for(int i = 0; i < ships.size(); i++) {
            ships[i]->Step();
        }
        world->Step(WORLD_STEP_DELTA, 6, 2);
        deltaAccumulation -= WORLD_STEP_DELTA;
    }
};

void World::Draw() {
    for(int i = 0; i < ships.size(); i++) {
        ships[i]->Draw();
    }
};
