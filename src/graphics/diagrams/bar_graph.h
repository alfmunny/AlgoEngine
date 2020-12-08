#pragma once
#include "graph.h"

namespace algo { namespace graphics {
  class BarGraph : public Graph {
    private:
      const Shader& shader;
    public:
      BarGraph(std::vector<float>& input, const Shader& shader);
      ~BarGraph();
  };
}}
