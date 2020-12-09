#pragma once
#include <models/square.h>
#include <shapes/bar.h>
#include "../static_renderer2d.h"
#include <deque>

namespace algo { namespace graphics {
  class Graph {
    protected:
      std::deque<const Square*> Q;
    public:
      inline const std::deque<const Square*> GetRenderables() { return Q; };
      inline const void Render() { StaticRenderer2D renderer; renderer.copy(GetRenderables()); renderer.flush(); };
  };
}}

