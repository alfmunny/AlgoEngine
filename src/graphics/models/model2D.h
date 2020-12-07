#pragma once
#include "glm/glm.hpp"
#include "vertexarray.h"
#include "indexbuffer.h"
#include "shader.h"

namespace algo { namespace models {
  
  class Model2D 
  {
    protected:
      glm::vec3 mPosition;
      glm::vec2 mSize;
      glm::vec4 mColor;
      graphics::VertexArray* vertexArray;
      graphics::IndexBuffer* indexbuffer;
      graphics::Shader& shader;

    public:
      Model2D(glm::vec3 position, glm::vec2 size, glm::vec4 color, graphics::Shader& shader)
        : mPosition(position), mSize(size), mColor(color), shader(shader)
      {}

      Model2D();
      virtual ~Model2D() = 0;
      inline const glm::vec3& getPosition() const { return mPosition; }
      inline const glm::vec2& getSize() const { return mSize; }
      inline const glm::vec4& getColor() const { return mColor; }
  };

} }
