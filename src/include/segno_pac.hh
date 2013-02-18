/* Phase-to-Amplitude Converters. */

#ifndef M_PI
#define M_PI 3.14159265358979323846264338
#endif

namespace Segno {

namespace PAC {

class Sine: public Vertex {
 public:
  Sine() : output(0.0f) {}
  float *ramp;
  float output;
  void tick();
};

class Saw: public Vertex {
 public:
  Saw() : output(0.0f) {}
  float *ramp;
  float output;
  void tick();
};

class Triangle: public Vertex {
 public:
  Triangle() : output(0.0f) {}
  float *ramp;
  float output;
  void tick();
};

class Square: public Vertex {
 public:
  Square() : output(0.0f) {}
  float *ramp;
  float output;
  void tick();
};

class Impulse: public Vertex {
  float last;
 public:
  Impulse() : last(0.0f), output(1.0f) {}
  float *ramp;
  float output;
  void tick();
};

} // PAC

} // Segno
