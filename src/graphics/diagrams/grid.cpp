#include "grid.h"

namespace algo { namespace graphics {
  Grid::Grid(int width, int height, const Shader& shader)
    : shader(shader) {
      for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 40; ++j) {
          Q.push_back((Square*) new Bar(-5.0f+i*0.2, -4.0f+j*0.2, 0.08, 0.08, shader));
        }
      }
  };

  Grid::~Grid() {
    for (const Square* s : Q)
      delete s;
  }
}}


