#include <GLFW/glfw3.h>
#include <stdio.h>
#include <math.h>

#include "world.h"
#include "ship.h"

Ship::Ship(b2World *world) {
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.linearDamping = 0.3f;
    bodyDef.angularDamping = 2.0f;
    body = world->CreateBody(&bodyDef);

    b2PolygonShape shape;
    shape.SetAsBox(1.0f, 2.0f);
    body->CreateFixture(&shape, 1.0f);
};

Ship::~Ship() {
};

void Ship::Control(int controls_) {
    controls = controls_;
};

void Ship::Step() {
    b2Vec2 lateralDirection = body->GetWorldVector(b2Vec2(1, 0));
    b2Vec2 lateralVelocity = b2Dot(lateralDirection, body->GetLinearVelocity()) * lateralDirection;
    body->ApplyForce(-10 * lateralVelocity, body->GetWorldPoint(b2Vec2(0, 0)), true);

    float acceleration = 0.0f;
    float torque = 0.0f;

    if(controls & SHIP_ACCELERATE) {
        acceleration += 400.0f;
    }
    if(controls & SHIP_REVERSE) {
        acceleration -= 50.0f;
    }
    if(controls & SHIP_YAW_LEFT) {
        torque += 50.0f;
    }
    if(controls & SHIP_YAW_RIGHT) {
        torque -= 50.0f;
    }

    body->ApplyForce(body->GetWorldVector(b2Vec2(0, acceleration)), body->GetWorldPoint(b2Vec2(0, 0)), true);
    body->ApplyTorque(torque, true);
};

void Ship::Draw() {
    b2Vec2 position = body->GetPosition();
    float angle = body->GetAngle();

    glPushMatrix();
    glTranslatef(position.x, position.y, 0);
    glRotatef(angle * 180 / M_PI, 0, 0, 1);
    glBegin(GL_QUADS);
    glVertex2f(-1.0, -2.0);
    glVertex2f(-1.0, 2.0);
    glVertex2f(1.0, 2.0);
    glVertex2f(1.0, -2.0);
    glEnd();
    glPopMatrix();
};
