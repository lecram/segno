/* Phase Accumulators. */

namespace Segno {

namespace PA {

class Ramp: public Vertex {
 public:
  Ramp() : output(0.0f) {}
  float *frequency;
  float output;
  void tick();
};

} // PA

} // Segno
