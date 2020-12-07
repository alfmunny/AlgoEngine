#include "square.h"

namespace algo { namespace graphics {
  Square::Square(glm::vec3 position, glm::vec2 size, glm::vec4 color, const Shader& shader) : 
    position(position), size(size), color(color), shader(shader)
  {
    vertexarray = new graphics::VertexArray();
    float vertices[] = { // positions          // colors           
        1.0f*size.x,  1.0f*size.y, 0.0f,   color.x, color.y, color.z, color.w,     // top right
        1.0f*size.x, -1.0f*size.y, 0.0f,   color.x, color.y, color.z, color.w,    // bottom right
        -1.0f*size.x, -1.0f*size.y, 0.0f,  color.x, color.y, color.z, color.w,     // bottom left
        -1.0f*size.x,  1.0f*size.y, 0.0f,  color.x, color.y, color.z, color.w    // top left
    };

    unsigned int indices[] = {
      0, 1, 3,
        1, 2, 3
    };

    graphics::Buffer buffer(vertices, sizeof(vertices) / sizeof(float), 7);
    vertexarray->addBuffer(&buffer, 0, 3, 0);
    vertexarray->addBuffer(&buffer, 1, 4, 3);
    indexbuffer = new IndexBuffer(indices, 6);
  }

  Square::~Square() 
  {
    delete vertexarray;
    delete indexbuffer;
  }
} }

