#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/glut.h>

using namespace std;

static int compileShader(unsigned int type, const string &source){
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int res;
    glGetShaderiv(id, GL_COMPILE_STATUS, &res);
    if(res == GL_FALSE){
        int len;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &len);
        char* msg = (char *)alloca(len * sizeof(char));
        glGetShaderInfoLog(id, len, &len, msg); 
        cout << "[ERR] : failed to compile " << ((type == GL_VERTEX_SHADER) ? "vertex" : "fragment") << " shader | " << msg << endl;
        glDeleteShader(id);
        return -1;
    }

    return id;
}

static unsigned int createShader(const string &vertexShader, const string &fragmentShader){
    unsigned int program = glCreateProgram();

    unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    // delete intermediate build files
    glDeleteShader(fs);
    glDeleteShader(fs);

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
    float triangle_positions[6] = {
        -0.5f, -0.5f,
        0.0f, 0.5f,
        0.5f, -0.5f
    };

    // generate buffer for triangle
    unsigned int triangle_buffer;
    glGenBuffers(1, &triangle_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, triangle_buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), triangle_positions, GL_STATIC_DRAW);
    // vertex attribute : postition
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (const void *) 0);
    glEnableVertexAttribArray(0);

    string vertexShader = 
        "#version 330 core\n"
        "#extension GL_ARB_separate_shader_objects : enable\n"
        "layout(location = 0) in vec4 position;\n"
        "\n"
        "void main()\n"
        "{\n"
        "   gl_Position = position;\n"
        "}\n";

    string fragmentShader = 
        "#version 330 core\n"
        "#extension GL_ARB_separate_shader_objects : enable\n"
        "layout(location = 0) out vec4 color;\n"
        "\n"
        "void main()\n"
        "{\n"
        "   color = vec4(0.2, 0.4, 0.7, 1.0);\n"
        "}\n";

    unsigned int shader = createShader(vertexShader, fragmentShader);
    glUseProgram(shader);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glDeleteProgram(shader);

    glfwTerminate();
    return 0;
}