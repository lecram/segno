/* Delay Line. */

namespace Segno {

namespace DL {

class DelayLine: public Vertex {
  float *buffer;
  int index;
  int size;
 public:
  float *input;
  float *delay;
  float output;
  DelayLine(float max_delay);
  void tick();
  ~DelayLine();
};

class DelayLineInterpolated: public Vertex {
  float *buffer;
  int index;
  int size;
 public:
  float *input;
  float *delay;
  float output;
  DelayLineInterpolated(float max_delay);
  void tick();
  ~DelayLineInterpolated();
};

} // DL

} // Segno
