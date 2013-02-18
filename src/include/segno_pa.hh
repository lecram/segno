/* Phase Accumulators. */

namespace PA {

class Ramp: public Vertex {
 public:
  Ramp() : output(0.0f) {}
  float *frequency;
  float output;
  void tick() {
    output += *frequency / sample_rate;
    output -= (output > 1.0f);
  }
};

} // PA
