/* High-level Effects. */

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
  Flanger() : delayline(0.1f);
  void plug();
  void tick();
};

} // FX

} // Segno
