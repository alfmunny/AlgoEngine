#pragma once
#include "renderer2d.h"
#include <deque>

namespace algo { namespace graphics {
  class StaticRenderer2D : public Renderer2D {
    private:
      std::deque<const Square*> renderQ;
    public:
      void push(const Square* model2d) override;
      void flush() override;
  };
} }
