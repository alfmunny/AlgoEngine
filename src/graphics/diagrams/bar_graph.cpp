#include "bar_graph.h"

namespace algo { namespace graphics {
  BarGraph::BarGraph(std::vector<float>& input, const Shader& shader)
    : shader(shader) {
    for (int i = 0; i < input.size(); ++i) {
      Q.push_back((Square*) new Bar(-5.0f + (float)i * 0.1f + 0.5, input[i], input[i], shader));
    }
  };

  BarGraph::~BarGraph() {
    for (const Square* s : Q)
      delete s;
  }
}}

