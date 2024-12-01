#include "config.h"

float backgroundColor[4] = {0.2f, 0.2f, 0.2f, 0.2f};

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }


}

// void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
//     if (action == GLFW_PRESS) {

//         std::cout << char(key);
//         // std::cout << "Key Pressed: " << char(key) << std::endl;
//     } else if (action == GLFW_RELEASE) {
//         // std::cout << "Key Released: " << char(key) << std::endl;
//     }
// }

int main(void)
{

    // Initializing OpenGL
    if (!glfwInit())
        exit(EXIT_FAILURE);

    // Specifying GLFW version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWmonitor *primaryMonitor = glfwGetPrimaryMonitor();
    const GLFWvidmode *mode = glfwGetVideoMode(primaryMonitor);

    // Creating a window
    // GLFWwindow *window = glfwCreateWindow(mode->width, mode->height, "First OpenGL Window", primaryMonitor, NULL);
    GLFWwindow *window = glfwCreateWindow(windowHeight, windowWidth, windowTitle, NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "[ERROR]: Couldn't Load OpenGL" << std::endl;
    }
    glfwSwapInterval(1);

    // glfwSetKeyCallback(window, keyCallback);

    while (!glfwWindowShouldClose(window))
    {

        glClearColor(backgroundColor[0], backgroundColor[1], backgroundColor[2], backgroundColor[3]);
        glClear(GL_COLOR_BUFFER_BIT);

        processInput(window);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);

    glfwTerminate();
    exit(EXIT_SUCCESS);
}