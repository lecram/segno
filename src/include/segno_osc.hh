/* Stand-alone oscillators. */

namespace Segno {

namespace Osc {

class Sine: public Vertex {
  float ramp;
  float default_amplitude;
  float default_offset;
  float default_phase;
 public:
  float *frequency;
  float *amplitude;
  float *offset;
  float *phase;
  float output;
  Sine();
  void tick();
};

class Saw: public Vertex {
  float ramp;
  float default_amplitude;
  float default_offset;
  float default_phase;
 public:
  float *frequency;
  float *amplitude;
  float *offset;
  float *phase;
  float output;
  Saw();
  void tick();
};

class Triangle: public Vertex {
  float ramp;
  float default_amplitude;
  float default_offset;
  float default_phase;
 public:
  float *frequency;
  float *amplitude;
  float *offset;
  float *phase;
  float output;
  Triangle();
  void tick();
};

class Square: public Vertex {
  float ramp;
  float default_amplitude;
  float default_offset;
  float default_phase;
 public:
  float *frequency;
  float *amplitude;
  float *offset;
  float *phase;
  float output;
  Square();
  void tick();
};

class Impulse: public Vertex {
  float ramp;
  float last;
  float default_amplitude;
  float default_offset;
  float default_phase;
 public:
  float *frequency;
  float *amplitude;
  float *offset;
  float *phase;
  float output;
  Impulse();
  void tick();
};

} // Osc

} // Segno
