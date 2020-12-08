#pragma once
#include "renderer2d.h"
#include <deque>
#include <diagrams/graph.h>

namespace algo { namespace graphics {
  class StaticRenderer2D : public Renderer2D {
    private:
      std::deque<const Square*> renderQ;
    public:
      StaticRenderer2D();
      StaticRenderer2D(Graph& graph);
      void push(const Square* square) override;
      void flush() override;
  };
} }
