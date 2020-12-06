#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "src/algo.h"

int main() {
  using namespace algo;
  using namespace graphics;
  Window window("AlgoEngine", 800, 600);

  Shader shader("src/shaders/shader.vs", "src/shaders/shader.fs");


  float vertices[] = {
     0.5f,  0.5f, 0.0f,  // top right
     0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f,  // bottom left
    -0.5f,  0.5f, 0.0f   // top left
  };

  float vertices2[] = {
     0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
    -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
     0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f
  };

  float vertices3[] = {
     1.0f,  0.0f, 0.0f,  
     0.5f, 0.6f, 0.0f,  
     0.0f, 0.0f, 0.0f,
  };


  unsigned int indices[]= {
    0, 1, 3,
    1, 2, 3
  };

  unsigned int VBOs[2], VAOs[2], EBO;
  glGenBuffers(2, VBOs);
  //glGenBuffers(1, &EBO);
  glGenVertexArrays(2, VAOs);

  glBindVertexArray(VAOs[0]);

  glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);

  //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  //glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);

  glBindVertexArray(VAOs[1]);
  glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices3), vertices3, GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
  while (!window.closed())
  {
    window.processInput();
    window.clear();
    shader.use();
    glBindVertexArray(VAOs[0]);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
    window.update();
  }

  glDeleteVertexArrays(2, VAOs);
  glDeleteBuffers(2, VBOs);
  return 0;
}
