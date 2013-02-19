/* Phase Accumulators. */

#ifndef SEGNO_PA_HH_
#define SEGNO_PA_HH_

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

#endif // SEGNO_PA_HH_
