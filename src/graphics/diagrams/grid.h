#pragma once
#include "graph.h"

namespace algo { namespace graphics {
  class Grid : public Graph {
    private:
      const Shader& shader;
    public:
      Grid(int width, int height, const Shader& shader);
      ~Grid();
  };
}}

