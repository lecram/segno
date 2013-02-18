/* Stand-alone oscillators. */

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
  Sine() {
    ramp = 0.0f;
    output = 0.0f;
    default_amplitude = 1.0f;
    default_offset = 0.0f;
    default_phase = 0.0f;
    amplitude = &default_amplitude;
    offset = &default_offset;
    phase = &default_phase;
  }
  void tick() {
    ramp += *frequency / sample_rate;
    ramp -= (ramp > 1.0f);
    output = sin(2 * M_PI * (ramp + *phase)) * *amplitude + *offset;
  }
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
  Saw() {
    ramp = 0.0f;
    output = 0.0f;
    default_amplitude = 1.0f;
    default_offset = 0.0f;
    default_phase = 0.0f;
    amplitude = &default_amplitude;
    offset = &default_offset;
    phase = &default_phase;
  }
  void tick() {
    float phased_ramp;

    ramp += *frequency / sample_rate;
    ramp -= (ramp > 1.0f);
    phased_ramp = ramp + *phase;
    phased_ramp -= (phased_ramp > 1.0f);
    if (phased_ramp < 0.5f)
      output = 2 * phased_ramp;
    else
      output = 2 * phased_ramp - 2;
    output = output * *amplitude + *offset;
  }
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
  Triangle() {
    ramp = 0.0f;
    output = 0.0f;
    default_amplitude = 1.0f;
    default_offset = 0.0f;
    default_phase = 0.0f;
    amplitude = &default_amplitude;
    offset = &default_offset;
    phase = &default_phase;
  }
  void tick() {
    float phased_ramp;

    ramp += *frequency / sample_rate;
    ramp -= (ramp > 1.0f);
    phased_ramp = ramp + *phase;
    phased_ramp -= (phased_ramp > 1.0f);
    if (phased_ramp < 0.25)
      output = 4 * phased_ramp;
    else if (phased_ramp >= 0.75)
      output = 4 * phased_ramp - 4;
    else
      output = 4 * (0.5f - phased_ramp);
    output = output * *amplitude + *offset;
  }
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
  Square() {
    ramp = 0.0f;
    output = 0.0f;
    default_amplitude = 1.0f;
    default_offset = 0.0f;
    default_phase = 0.0f;
    amplitude = &default_amplitude;
    offset = &default_offset;
    phase = &default_phase;
  }
  void tick() {
    float phased_ramp;

    ramp += *frequency / sample_rate;
    ramp -= (ramp > 1.0f);
    phased_ramp = ramp + *phase;
    phased_ramp -= (phased_ramp > 1.0f);
    output = (phased_ramp < 0.5f) ? 1.0f : -1.0f;
    output = output * *amplitude + *offset;
  }
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
  Impulse() {
    ramp = 0.0f;
    output = 0.0f;
    default_amplitude = 1.0f;
    default_offset = 0.0f;
    default_phase = 0.0f;
    amplitude = &default_amplitude;
    offset = &default_offset;
    phase = &default_phase;
  }
  void tick() {
    float phased_ramp;

    ramp += *frequency / sample_rate;
    ramp -= (ramp > 1.0f);
    phased_ramp = ramp + *phase;
    phased_ramp -= (phased_ramp > 1.0f);
    output = (ramp < last) ? 1.0f : 0.0f;
    output = output * *amplitude + *offset;
    last = ramp;
  }
};

} // Osc
