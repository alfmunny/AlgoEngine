#pragma once
#include <graphics.h>

namespace algo {
  class QuickSort
  {
    private:
      std::vector<float> input;
      void sort(int lo, int hi);
      int parition(int lo, int hi);
      void exch(int i, int j);
      std::vector<std::vector<float>> playback;
      graphics::Shader& shader;
      graphics::StaticRenderer2D renderer;
      double timer;
      double lastTime;
      double deltaTime;
      int currentFrame;
    public:
      QuickSort(std::vector<float>& input, graphics::Shader& shader);
      void sort();
      void render();
      void update();
      inline int getSize() { return input.size(); }
      inline void show() { for (int i = 0; i < input.size(); ++i) { std::cout << input[i] << " "; } std::cout << std::endl; }
  } ;
}
