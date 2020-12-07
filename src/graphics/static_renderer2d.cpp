#include "static_renderer2d.h"
#include "models/square.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace algo { namespace graphics {
  void StaticRenderer2D::push(const Square* square)
  {
    renderQ.push_back(square);
  }

  void StaticRenderer2D::flush() 
  {
    while(!renderQ.empty())
    {
      const Square* square = renderQ.front();
      square->getVAO()->bind();
      square->getIBO()->bind();
      square->getShader().setMat4("model", glm::translate(glm::mat4(1.0f), square->getPosition()));
      glDrawElements(GL_TRIANGLES, square->getIBO()->getCount(), GL_UNSIGNED_INT, 0);
      square->getVAO()->unbind();
      square->getIBO()->unbind();
      renderQ.pop_front();
    }
  }

} }
