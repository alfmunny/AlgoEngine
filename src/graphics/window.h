#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace algo{
  namespace graphics {

    class Window
    {
      private:
        const char *mName;
        int mWidth, mHeight;
        GLFWwindow *mWindow;
        bool init();

      public:
        Window(const char *name, int width, int height);
        ~Window();
        void processInput();
        void update();
        void clear() const;
        bool closed() const;
    };
    void framebuffer_size_callback(GLFWwindow* window, int width, int height); 
  }
}
