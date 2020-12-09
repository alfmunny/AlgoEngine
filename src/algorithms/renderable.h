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
      Renderable(std::vector<float>& input, const graphics::Shader& shader) 
        : input(input), shader(shader) {
          lastTime = glfwGetTime();
          deltaTime = 0;
          currentFrame = 0;
          playback.push_back(input);
      };

      ~Renderable() {};

      virtual void Perform() = 0;

      virtual void AddFrame() {
        playback.push_back(input);
      };

      virtual void ForwardFrame() {
        if (currentFrame < playback.size() - 1) {
          currentFrame++;
        };
      }

      template <typename T> void Render() {
        if (currentFrame >= playback.size()) currentFrame = playback.size() - 1;
        std::vector<float> frame = playback[currentFrame];
        T graph(frame, shader);
        graph.Render();
      };

      template <typename T> void RenderAndNext() { 
        Render<T>(); 
        ForwardFrame(); 
      }

      template <typename T> void RenderPlayBack(double frame_interval = 0.033) { 
        double now = glfwGetTime();
        deltaTime += now - lastTime;
        lastTime = now;
        if (deltaTime >= frame_interval) {
          RenderAndNext<T>();
          deltaTime = 0;
        } else {
          Render<T>();
        }
      };

      inline void ResetFrame() { currentFrame = 0; }
      inline int GetInputSize() { return input.size(); }
      inline void Show() { for (int i = 0; i < input.size(); ++i) { std::cout << input[i] << " "; } std::cout << std::endl; }
  };
} }
