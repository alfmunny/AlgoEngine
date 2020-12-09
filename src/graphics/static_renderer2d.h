#pragma once
#include "renderer2d.h"
#include <deque>

namespace algo { namespace graphics {
  class StaticRenderer2D : public Renderer2D {
    private:
      std::deque<const Square*> renderQ;
    public:
      StaticRenderer2D();
      void push(const Square* square) override;
      void copy(const std::deque<const Square*> renderables) override;
      void flush() override;
  };
} }
