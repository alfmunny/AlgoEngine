#pragma once
#include <models/square.h>
#include <shapes/bar.h>
#include <deque>

namespace algo { namespace graphics {
  class Graph {
    protected:
      std::deque<const Square*> Q;
    public:
      inline const std::deque<const Square*> GetRenderables() { return Q; };
  };
}}

