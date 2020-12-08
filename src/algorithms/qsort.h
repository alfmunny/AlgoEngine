#pragma once
#include <graphics.h>
#include <renderable.h>

namespace algo { namespace algorithms {

  class QuickSort : public Renderable
  {
    private:
      void sort(int lo, int hi);
      int parition(int lo, int hi);
      void exch(int i, int j);
      void sort();
    public:
      QuickSort(std::vector<float>& input, const graphics::Shader& shader);
      ~QuickSort();
      void Perform() override;
  } ;
} }
