#include "qsort.h"
#include <thread>
#include <chrono>

namespace algo { namespace algorithms {

  QuickSort::QuickSort(std::vector<float>& input, const graphics::Shader& shader)
    : Renderable(input, shader)
  {
  }

  int QuickSort::parition(int lo, int hi) 
  {
    int i = lo, j = hi+1;

    while(true) 
    {
      while(input[++i] < input[lo]) if (i == hi) break;
      while(input[lo] < input[--j]) if (j == lo) break;
      if (i >= j) break;
      exch(i, j);
    }
    exch(lo, j);
    return j;
  }

  void QuickSort::exch(int i, int j) {
    float tmp = input[i]; 
    input[i] = input[j]; 
    input[j] = tmp;
    AddFrame();
  }

  void QuickSort::sort(int lo, int hi)
  {
    if (hi <= lo) return;
    int j = parition(lo, hi);
    sort(lo, j-1);
    sort(j+1, hi);
  }

  void QuickSort::sort() {
    playback.clear();
    playback.push_back(input);
    sort(0, input.size()-1);
  }

  void QuickSort::Perform() {
    sort();
  }

  QuickSort::~QuickSort() {

  }
} }
