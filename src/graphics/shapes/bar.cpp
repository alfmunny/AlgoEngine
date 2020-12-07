#include "bar.h"

namespace algo { namespace graphics {
  Bar::Bar(float x, float y, float height, const Shader& shader)
    : Square(glm::vec3(x, y, 0), glm::vec2(0.01f, height), glm::vec4(1.0f, 0.0f, 1.0f, 1.0f), shader)
  {

  }

  Bar::Bar(float x, float y, float height, glm::vec4 color, const Shader& shader)
    : Square(glm::vec3(x, y, 0), glm::vec2(0.01f, height), color, shader) 
  {

  }

  Bar::Bar(float x, float y, float width, float height, glm::vec4 color, const Shader& shader)
    : Square(glm::vec3(x, y, 0), glm::vec2(width, height), color, shader) 
  {

  }

  Bar::Bar(float x, float y, float width, float height, const Shader& shader)
    : Square(glm::vec3(x, y, 0), glm::vec2(width, height), glm::vec4(1.0f, 0.0f, 1.0f, 1.0f), shader) 
  {

  }

  Bar::~Bar()
  {

  }
}}
