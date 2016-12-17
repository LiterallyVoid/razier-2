#include <GLFW/glfw3.h>
#include <stdio.h>
#include "ship.h"
#include "world.h"

int main(void) {
    if(!glfwInit()) {
        fprintf(stderr, "Couldn't initialize GLFW.\n");
        return 1;
    }

    GLFWwindow* window = glfwCreateWindow(640, 480, "Razier 2", NULL, NULL);
    if(!window) {
        fprintf(stderr, "Couldn't create a window.\n");
        glfwTerminate();
        return 1;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    double oldTime = glfwGetTime();

    World world;
    Ship *ship = world.CreateShip();

    while(!glfwWindowShouldClose(window)) {
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-width / 20, width / 20, -height / 20, height / 20, -1, 1);
        glMatrixMode(GL_MODELVIEW);

        double time = glfwGetTime();
        double delta = time - oldTime;
        oldTime = time;
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        {
            int shipControls = 0;
            if(glfwGetKey(window, 'W')) shipControls |= SHIP_ACCELERATE;
            if(glfwGetKey(window, 'S')) shipControls |= SHIP_REVERSE;
            if(glfwGetKey(window, 'A')) shipControls |= SHIP_YAW_LEFT;
            if(glfwGetKey(window, 'D')) shipControls |= SHIP_YAW_RIGHT;
            ship->Control(shipControls);
        }

        world.Step(delta);
        world.Draw();

        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();
};
