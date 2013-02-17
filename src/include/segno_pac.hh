/* Phase-to-Amplitude Converters. */

#ifndef M_PI
#define M_PI 3.14159265358979323846264338
#endif

namespace PAC {

  class Sine: public Vertex {
    public:
      Sine() : output(0.0f) {}
      float *ramp;
      float output;
      void tick() {
        output = sin(2 * M_PI * *ramp);
      }
  };

  class Saw: public Vertex {
    public:
      Saw() : output(0.0f) {}
      float *ramp;
      float output;
      void tick() {
        if (*ramp < 0.5f)
          output = 2 * *ramp;
        else
          output = 2 * *ramp - 2;
      }
  };

  class Triangle: public Vertex {
    public:
      Triangle() : output(0.0f) {}
      float *ramp;
      float output;
      void tick() {
        if (*ramp < 0.25)
          output = 4 * *ramp;
        else if (*ramp >= 0.75)
          output = 4 * *ramp - 4;
        else
          output = 4 * (0.5f - *ramp);
      }
  };

  class Square: public Vertex {
    public:
      Square() : output(0.0f) {}
      float *ramp;
      float output;
      void tick() {
        output = (*ramp < 0.5f) ? 1.0f : -1.0f;
      }
  };

  class Impulse: public Vertex {
      float last;
    public:
      Impulse() : last(0.0f), output(1.0f) {}
      float *ramp;
      float output;
      void tick() {
        output = (*ramp < last) ? 1.0f : 0.0f;
        last = *ramp;
      }
  };

}
