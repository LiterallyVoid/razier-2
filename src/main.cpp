#include <GLFW/glfw3.h>
#include "ship.h"

int main(void) {
    if(!glfwInit()) {
        return;
    }

    GLFWwindow* window = glfwCreateWindow(640, 480, "Razier 2", NULL, NULL);
    if(!window) {
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    double oldTime = glfwGetTime();

    while(!glfwWindowShouldClose(window)) {
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);

        double time = glfwGetTime();
        double delta = time - oldTime;
        oldTime = time;
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glCallList();

        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();
};
