#include <iostream>
#include <thread>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "src/algo.h"
#include "src/graphics/stb_image.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

const unsigned int SCR_WIDTH = 1200;
const unsigned int SCR_HEIGHT = 800;

int main() {
  using namespace algo;
  using namespace graphics;

  Window window("AlgoEngine", SCR_WIDTH, SCR_HEIGHT);
  Shader shader("src/shaders/shader.vs", "src/shaders/shader.fs");
  shader.use();
  glm::mat4 view          = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
  glm::mat4 projection    = glm::mat4(1.0f);
  projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
  view       = glm::translate(view, glm::vec3(0.0f, 0.0f, -10.0f));
  shader.setMat4("projection", projection);
  shader.setMat4("view", view);

  std::vector<float> input;

  for (int i = 0; i < 100; ++i)
  {
    float h = (std::rand() % 100 + 1) / 100.0f;
    input.push_back(h);
  }

  algorithms::QuickSort qs(input, shader);
  algorithms::Renderable* qsr = &qs; 

  qsr->Perform();
  
  Grid g(1, 1, shader);
  StaticRenderer2D renderer(g);

  double now = glfwGetTime(), lastTime = now;
  double deltaTime = 0;

  while (!window.closed())
  {
    window.processInput();
    window.clear();

    now = glfwGetTime();
    deltaTime += now - lastTime;
    lastTime = now;
    if (deltaTime >= 0.1) 
    {
      deltaTime = 0;
    }

    //qsr->ForwardFrame();
    //qsr->Render();
    for (auto x : g.GetRenderables())
      renderer.push(x);
    renderer.flush();
    window.update();
  }

  return 0;
}
