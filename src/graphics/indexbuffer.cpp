#include "indexbuffer.h"

namespace algo { namespace graphics {
  IndexBuffer::IndexBuffer(GLuint* data, GLsizei count) 
    : mCount(count)
  {
    glGenBuffers(1, &mBufferID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mBufferID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), data, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
  }

  IndexBuffer::~IndexBuffer()
  {
    glDeleteBuffers(1, &mBufferID);
  }

  void IndexBuffer::bind() const 
  {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mBufferID);
  }

  void IndexBuffer::unbind() const
  {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
  }

} }

