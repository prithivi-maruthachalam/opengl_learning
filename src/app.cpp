#include <iostream>
#include <fstream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/glut.h>
#include <string>
#include <csignal>
#include <sstream>

#define ASSERT(x) if (!(x)) raise(SIGTRAP)
#define GL_CALL(x) glClearError();\
    x;\
    ASSERT(glLogCall(#x, __FILE__, __LINE__))

using namespace std;

static void glClearError(){
    while(glGetError() != GL_NO_ERROR)
        ;
}

static bool glLogCall(const char* functionName, const char* fileName, int line){
    while(GLenum error = glGetError()){
        cout << "[ERR] : OpenGL Error(" << error << ")" << endl;
        cout << "\tin: " << fileName << endl;
        cout << "\tat: " << functionName << endl;
        cout << "\ton: " << line << endl << endl;
        return false;
    }

    return true;
}

int main(void) {
    return 0;
}