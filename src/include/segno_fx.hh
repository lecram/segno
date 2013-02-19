/* High-level Effects. */

#ifndef SEGNO_FX_HH_
#define SEGNO_FX_HH_

namespace Segno {

namespace FX {

class Flanger: public Vertex {
  Osc::Triangle lfo;
  DL::DelayLineInterpolated delayline;
  Op::Mul fb_mul;
  Op::Add fb_add;
  Op::Mul dry_mul;
  Op::Mul wet_mul;
  Op::Add mix;
  float lfo_amplitude;
  float lfo_offset;
 public:
  float *input;
  float *frequency;
  float *depth;
  float *tone;
  float *feedback;
  float *dry;
  float *wet;
  float output;
  Flanger();
  void plug();
  void tick();
};

} // FX

} // Segno

#endif // SEGNO_FX_HH_
