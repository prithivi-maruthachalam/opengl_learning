#include<GLFW/glfw3.h>

#include<iostream>
using namespace std;

void glfwErrorCallback(int error, const char* description) {
    fprintf(stderr, "Error: %d | %s\n", error, description);
}

int main(void) {
    // init glfw
    if(glfwInit() == GLFW_FALSE){
        cout << "GLFW initialization failed" << endl;
        return EXIT_FAILURE;
    }

    // set error callback function for glfw
    glfwSetErrorCallback(glfwErrorCallback);

    // create a window and context
    GLFWwindow* window = glfwCreateWindow(640, 480, "Let's teach me openGL", NULL, NULL);
    if(window == NULL){
        cout << "Window or Context creation failed" << endl;
        glfwTerminate();
        return EXIT_FAILURE;
    }

    // make this the current context
    glfwMakeContextCurrent(window);

    // WINDOW LOOP
    while(!glfwWindowShouldClose(window)){
        // clear the screen
        glClear(GL_COLOR_BUFFER_BIT);

        // swap front and back buffers
        glfwSwapBuffers(window);

        // poll for events and process them
        glfwPollEvents();
    }

    // destroy window and context
    glfwDestroyWindow(window);

    // terminate glfw
    glfwTerminate();

    return EXIT_SUCCESS;
}
