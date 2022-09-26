#include<GL/glew.h>
#include<GLFW/glfw3.h>

#include<cstdio>
#include<cstdlib>

#define LOW_RES_WIDTH 640
#define LOW_RES_HEIGHT 480
#define DIM 2
#define TRIANGLE_VERTICES 3

void glfwErrorCallback(int error, const char* description) {
	fprintf(stderr, "[GLFW] Error: %d | %s\n", error, description);
}

int main(void) {
	fprintf(stdout, "\n[INFO]  : Starting...\n");

    // init glfw
	if(glfwInit() == GLFW_FALSE){
        fprintf(stderr, "[ERROR] : GLFW initialization failed\n\n");
		return EXIT_FAILURE;
	}

   
	// set error callback function for glfw
	glfwSetErrorCallback(glfwErrorCallback);
	
    fprintf(stdout, "[INFO]  : Starting window creation...\n");

	// height and width for window
	int width = LOW_RES_WIDTH;
	int height = LOW_RES_HEIGHT;

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
        fprintf(stderr, "[ERROR] : Window or Context creation failed\n\n");
		glfwTerminate();
		return EXIT_FAILURE;
	}

	// make this the current context
	glfwMakeContextCurrent(window);

    fprintf(stdout, "[INFO]  : Created window with width: %dpx and height: %dpx\n", width, height);
    
    // init glew
    GLenum error = glewInit();
    if(error != GLEW_OK){
        fprintf(stderr, "[ERROR] : GLEW initialization failed. %s\n\n", glewGetErrorString(error));
        return EXIT_FAILURE;
    }
    
    // log glew and opengl versions
    fprintf(stdout, "[INFO]  : Using GLEW %s\n", glewGetString(GLEW_VERSION));
    fprintf(stdout, "[INFO]  : Using GL %s\n", glGetString(GL_VERSION));

    // triangle positions
    float positions[DIM * TRIANGLE_VERTICES] = {
        // x    // y
        0.5f,   0.5f,
       -0.5f,   0.5f,
        0,     -0.5f,
    };
    const int positionIndex = 0;

    fprintf(stdout, "[INFO]  : Setting up buffers for triangle...\n");

    // first triangle
    unsigned int triangleBuffer;
    glGenBuffers(1, &triangleBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, triangleBuffer);  /* Bind Buffer is analogous to selecting our buffer. So, then glBufferData is called, it knows what buffer to use. */
    glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

    glVertexAttribPointer(positionIndex, DIM, GL_FLOAT, GL_FALSE, sizeof(float) * DIM, (const void*)positionIndex);
    glEnableVertexAttribArray(positionIndex);

    fprintf(stdout, "[INFO]  : Buffers and Vertices set up for triangle\n");

    // reset current buffer
    glBindBuffer(GL_ARRAY_BUFFER, 0);

	// WINDOW LOOP
	while(!glfwWindowShouldClose(window)){
		// clear the screen
		glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, positionIndex, TRIANGLE_VERTICES);

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
