#include "renderable.h"

namespace algo { namespace algorithms {
  Renderable::Renderable(std::vector<float>& input, const graphics::Shader& shader) 
    : input(input), shader(shader) {
  }

  void Renderable::Render() {
    if (currentFrame >= playback.size()) currentFrame = playback.size() - 1;
    std::vector<float> frame = playback[currentFrame];
    graphics::BarGraph bargraph(frame, shader);
    graphics::StaticRenderer2D renderer(bargraph);
    renderer.flush();
  }

  void Renderable::ForwardFrame() {
    if (currentFrame < playback.size() - 1) {
      currentFrame++;
    }
  }

  void Renderable::AddFrame() {
    playback.push_back(input);
  }

  Renderable::~Renderable() {

  }

} }

