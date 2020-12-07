#pragma once
#include <shapes/bar.h>

namespace algo { namespace graphics {
  class BarGraph
  {
    private:
      std::vector<Square*> Q;
      const Shader& shader;
    public:
      BarGraph(float* input, int size, const Shader& shader);
      ~BarGraph();
      inline const std::vector<Square*> getObj() { return Q; };
  };
}}
