#include "qsort.h"
#include <thread>
#include <chrono>

namespace algo { namespace algorithms {

  int QuickSort::parition(int lo, int hi) {
    int i = lo, j = hi+1;
    while(true) 
    {
      while(this->input[++i] < this->input[lo]) if (i == hi) break;
      while(this->input[lo] < this->input[--j]) if (j == lo) break;
      if (i >= j) break;
      exch(i, j);
    }
    exch(lo, j);
    return j;
  }

  void QuickSort::exch(int i, int j) {
    float tmp = this->input[i]; 
    this->input[i] = this->input[j]; 
    this->input[j] = tmp;
    this->AddFrame();
  }

  void QuickSort::sort(int lo, int hi) {
    if (hi <= lo) return;
    int j = parition(lo, hi);
    sort(lo, j-1);
    sort(j+1, hi);
  }

  void QuickSort::sort() {
    this->playback.clear();
    this->playback.push_back(this->input);
    sort(0, this->input.size()-1);
  }

} }
