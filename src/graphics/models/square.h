#pragma once
#include <glm/glm.hpp>
#include <vertexarray.h>
#include <indexbuffer.h>
#include <shader.h>

namespace algo { namespace graphics {
  class Square
  {
    private:
      glm::vec3 position;
      glm::vec2 size;
      glm::vec4 color;
      IndexBuffer* indexbuffer;
      VertexArray* vertexarray;
      const Shader& shader;

    public:
      Square(glm::vec3 position, glm::vec2 size, glm::vec4 color, const Shader& shader);
      ~Square();
      inline const glm::vec3 getPosition() const { return position; }
      inline const glm::vec2 getSize() const { return size; }
      inline const glm::vec4 getColor() const { return color; }
      inline const IndexBuffer* getIBO() const { return indexbuffer; }
      inline const VertexArray* getVAO() const { return vertexarray; }
      inline const Shader& getShader() const { return shader; }
  };
}}
