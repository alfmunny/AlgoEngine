#include "qsort.h"
#include <thread>
#include <chrono>

namespace algo {
  QuickSort::QuickSort(std::vector<float>& input, graphics::Shader& shader)
    : input(input), shader(shader)
  {
    timer = glfwGetTime();
    lastTime = timer;
    deltaTime = 0;
    playback.push_back(input);
    currentFrame = 0;
  };

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
      playback.push_back(input);
  }

  void QuickSort::sort(int lo, int hi)
  {
    if (hi <= lo) return;
    int j = parition(lo, hi);
    sort(lo, j-1);
    sort(j+1, hi);
  }

  void QuickSort::sort()
  {
    playback.clear();
    playback.push_back(input);
    sort(0, input.size()-1);
  }

  void QuickSort::update() 
  {
    if (currentFrame < playback.size())
    {
      currentFrame++;
    }
  }

  void QuickSort::render()
  {
    if (currentFrame >= playback.size()) currentFrame = playback.size() - 1;
    std::vector<float> frame = playback[currentFrame];
    for (int i = 0; i < frame.size(); ++i)
    {
      renderer.push((graphics::Square*) new graphics::Bar(-5.0f + (float)i * 0.1f + 0.5, frame[i], frame[i], shader));
    }
    std::cout << playback.size() << ", " << currentFrame << std::endl;
    renderer.flush();
  }
}

