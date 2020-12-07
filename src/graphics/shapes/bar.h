#pragma once
#include <models/square.h>

namespace algo { namespace graphics {
  class Bar : public Square
  {
    public:
      Bar(float x, float y, float height, const Shader& shader);
      Bar(float x, float y, float height, glm::vec4 color, const Shader& shader);
      Bar(float x, float y, float width, float height, const Shader& shader);
      Bar(float x, float y, float width, float height, glm::vec4 color, const Shader& shader);
      ~Bar();
  };
}}
