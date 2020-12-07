#pragma once
#include <glad/glad.h>

namespace algo { namespace graphics {
  class Buffer
  {
    private: 
      GLuint mBufferID;
      GLuint mComponentCount;
    public:
      Buffer(float* data, GLsizei count, GLuint componentCount);
      ~Buffer();
      void bind() const;
      void unbind() const;
      inline GLuint getComponentCount() const { return mComponentCount; }
  };
} }

