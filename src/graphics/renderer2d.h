#pragma once
#include "models/square.h"

namespace algo { namespace graphics {
  class Renderer2D
  {
    public: 
      virtual void push(const Square* square) = 0;
      virtual void flush() = 0;
  };
} }