#include<GLFW/glfw3.h>

#include<iostream>
using namespace std;

#define LOW_RES_WIDTH 640
#define LOW_RES_HEIGHT 480

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
	
	cout << "Starting window creation..." << endl;

	// get primary monitor
	
	// height and width for window
	int width = LOW_RES_WIDTH;
	int height = LOW_RES_WIDTH;

	// reference to primary monitor
	GLFWmonitor* primaryMonitor = NULL;

	// resize for non-dev version
	#ifndef WINDOW_DEV
		primaryMonitor = glfwGetPrimaryMonitor();
		
		const GLFWvidmode* videomode = glfwGetVideoMode(primaryMonitor);
		width = videomode->width;
		height = videomode->height;
	#endif
	
	// create a window and context
	GLFWwindow* window = glfwCreateWindow(width, height, "Let's teach me openGL", primaryMonitor, NULL);
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

        glBegin(GL_TRIANGLES);	// specify that we're drawing triangles
        glVertex2f(0.5f, 0.5f);
        glVertex2f(-0.5f, 0.5f);
        glVertex2f(0, -0.5f);
        glEnd();	// end vertex specification

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
