#include "vertexarray.h"

namespace algo { namespace graphics {

  VertexArray::VertexArray() 
  {
    glGenVertexArrays(1, &mArrayID);
  }

  VertexArray::~VertexArray() 
  {
    for (int i = 0; i < mBuffers.size(); ++i)
      delete mBuffers[i];

    glDeleteVertexArrays(1, &mArrayID);
  }

  void VertexArray::addBuffer(Buffer* buffer, int index, int count, int offset) 
  {
    bind();
    buffer->bind();
    glVertexAttribPointer(index, count, GL_FLOAT, GL_FALSE, buffer->getComponentCount() * sizeof(float), (void*)(offset * sizeof(float)));
    glEnableVertexAttribArray(index);
    buffer->unbind();
    unbind();
  }

  void VertexArray::bind() const
  {
    glBindVertexArray(mArrayID);
  }

  void VertexArray::unbind() const
  {
    glBindVertexArray(0);
  }

} }
