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

struct ShaderProgramSource {
    string vertextSource;
    string fragmentSource;
};

static ShaderProgramSource parseShader(const string &filepath){
    ifstream stream(filepath);
    if(!stream){
        cout << "[ERR] : error reading file" << endl;
        return {
            "", ""
        }; 
    }

    enum class ShaderType{
        NONE = -1, VERTEX = 0, FRAGMENT = 1
    };

    string line;
    stringstream ss[2];
    ShaderType shaderType = ShaderType::NONE;
    while(getline(stream, line)){
        // check for shader definition
        if(line.find("#shader") != string::npos){
            // find shader type
            if(line.find("vertex") != string::npos){
                shaderType = ShaderType::VERTEX;
            } else if(line.find("fragment") != string::npos){
                shaderType = ShaderType::FRAGMENT;
            }
        } else {
            ss[(int)shaderType] << line << endl;
        }
    }

    return {
        ss[0].str(),
        ss[1].str()
    };
}

static int compileShader(unsigned int type, const string &source){
    GL_CALL(unsigned int id = glCreateShader(type));
    const char* src = source.c_str();
    GL_CALL(glShaderSource(id, 1, &src, nullptr));
    GL_CALL(glCompileShader(id));

    int res;
    glGetShaderiv(id, GL_COMPILE_STATUS, &res);
    if(res == GL_FALSE){
        int len;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &len);
        char* msg = (char *)alloca(len * sizeof(char));
        glGetShaderInfoLog(id, len, &len, msg); 
        cout << "[ERR] : failed to compile " << ((type == GL_VERTEX_SHADER) ? "vertex" : "fragment") << " shader | " << msg << endl;
        GL_CALL(glDeleteShader(id));
        return -1;
    }

    return id;
}

static unsigned int createShader(const string &vertexShader, const string &fragmentShader){
    GL_CALL(unsigned int program = glCreateProgram());

    unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);

    GL_CALL(glAttachShader(program, vs));
    GL_CALL(glAttachShader(program, fs));
    GL_CALL(glLinkProgram(program));
    GL_CALL(glValidateProgram(program));

    // delete intermediate build files
    GL_CALL(glDeleteShader(fs));
    GL_CALL(glDeleteShader(fs));

    return program;
}

int main(void)
{
    // create a window object
    GLFWwindow* window;
    const char* err_desc;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwGetError(&err_desc);
        cout << "[ERR] : " << err_desc << endl;
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    // glew init after creating a valid context
    GLenum status =  glewInit();
    if(status != GLEW_OK){
        cout << "[ERR] : " << glewGetErrorString(status) << endl;
        return -1;
    }
    cout << "[STA] : using glew version " << glewGetString(GLEW_VERSION) << endl; 


    // triangle vertices
    float triangle_positions[8] = {
        -0.5f, -0.5f,   // 0
        0.5f, -0.5f,    // 1
        0.5f, 0.5f,     // 2
        -0.5f, 0.5f,    // 3
    };

    // indices for index buffer
    unsigned int triangle_indices[6] = {
        0, 1, 2, 
        2, 3, 0
    };

    // generate buffer for triangle
    unsigned int triangle_buffer;
    GL_CALL(glGenBuffers(1, &triangle_buffer));
    GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, triangle_buffer));
    GL_CALL(glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), triangle_positions, GL_STATIC_DRAW));

    // vertex attribute : postition
    GL_CALL(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (const void *) 0));
    GL_CALL(glEnableVertexAttribArray(0));

    unsigned int ibuf;
    GL_CALL(glGenBuffers(1, &ibuf));
    GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibuf));
    GL_CALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), triangle_indices, GL_STATIC_DRAW));

    ShaderProgramSource source = parseShader("../res/shaders/basic.glsl");
    unsigned int shader = createShader(source.vertextSource, source.fragmentSource);
    GL_CALL(glUseProgram(shader));

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        GL_CALL(glClear(GL_COLOR_BUFFER_BIT));

        GL_CALL(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glDeleteProgram(shader);

    glfwTerminate();
    return 0;
}