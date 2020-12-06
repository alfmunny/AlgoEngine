#include "window.h"
#include <iostream>

namespace algo {
  namespace graphics {

    Window::Window(const char *name, int width, int height)
    {
      mName = name;
      mWidth = width;
      mHeight = height;
      if (!init())
        glfwTerminate();
    }

    Window::~Window() 
    {
      glfwTerminate();
    }


    bool Window::init()
    {
      glfwInit();
      glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
      glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
      glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
      glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

      mWindow= glfwCreateWindow(800, 600, "AlgoEngie", NULL, NULL);
      glfwMakeContextCurrent(mWindow);
      glfwSetFramebufferSizeCallback(mWindow, framebuffer_size_callback);

      if (mWindow == NULL)
      {
          std::cout << "Failed to create GLFW window" << std::endl;
          return false;
      }

      if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
      {
          std::cout << "Failed to initialize GLAD" << std::endl;
          return false;
      }
      return true;
    }

    void Window::clear() const 
    {
      glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT);
    }

    void Window::update()
    {
      glfwSwapBuffers(mWindow);
      glfwPollEvents();
    }
 
    bool Window::closed() const
    {
      return glfwWindowShouldClose(mWindow) == 1;
    }

    void Window::processInput()
    {
      if(glfwGetKey(mWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
          glfwSetWindowShouldClose(mWindow, true);
    }

    void framebuffer_size_callback(GLFWwindow* window, int width, int height)
    {
      glViewport(0, 0, width, height);
    }
  }

}
