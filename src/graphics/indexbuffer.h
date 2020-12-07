#pragma once
#include <glad/glad.h>

namespace algo { namespace graphics {
  class IndexBuffer
  {
    private: 
      GLuint mBufferID;
      GLuint mCount;
    public:
      IndexBuffer(unsigned int* data, GLsizei count);
      ~IndexBuffer();
      void bind() const;
      void unbind() const;
      inline GLuint getCount() const { return mCount; }
  };
} }


