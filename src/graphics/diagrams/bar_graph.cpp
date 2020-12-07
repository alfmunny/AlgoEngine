#include "bar_graph.h"

namespace algo { namespace graphics {
  BarGraph::BarGraph(float* input, int size, const Shader& shader)
    : shader(shader)
  {
    for (int i = 0; i < size; ++i) 
    {
      Square* el = new Bar(-1.0f + (float)i / (float) size * el->getSize().x, 0, 0.01, input[i]*1.0, shader);
      Q.push_back(el);
    }
  };

  BarGraph::~BarGraph() 
  {
    for ( Square* s : Q )
      delete s;
  }
}}

