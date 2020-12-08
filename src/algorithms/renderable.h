#pragma once
#include <graphics.h>
#include <vector>

namespace algo { namespace algorithms {
  class Renderable {
    protected:
      const graphics::Shader& shader;
      double lastTime;
      double deltaTime;
      int currentFrame;
      std::vector<float> input;
      std::vector<std::vector<float>> playback;
    public:
      Renderable(std::vector<float>& input, const graphics::Shader& shader);
      ~Renderable();
      virtual void Perform() = 0;
      virtual void AddFrame();
      virtual void ForwardFrame();
      virtual void Render();
      inline int GetInputSize() { return input.size(); }
      inline void Show() { for (int i = 0; i < input.size(); ++i) { std::cout << input[i] << " "; } std::cout << std::endl; }
  };
} }
