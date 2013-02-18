/* Stand-alone oscillators. */

#include "segno_osc.hh"

namespace Segno {

namespace Osc {

Sine::Sine() {
  ramp = 0.0f;
  output = 0.0f;
  default_amplitude = 1.0f;
  default_offset = 0.0f;
  default_phase = 0.0f;
  amplitude = &default_amplitude;
  offset = &default_offset;
  phase = &default_phase;
}

void
Sine::tick() {
  ramp += *frequency / sample_rate;
  ramp -= (ramp > 1.0f);
  output = sin(2 * M_PI * (ramp + *phase)) * *amplitude + *offset;
}


Saw::Saw() {
  ramp = 0.0f;
  output = 0.0f;
  default_amplitude = 1.0f;
  default_offset = 0.0f;
  default_phase = 0.0f;
  amplitude = &default_amplitude;
  offset = &default_offset;
  phase = &default_phase;
}

void
Saw::tick() {
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


Triangle::Triangle() {
  ramp = 0.0f;
  output = 0.0f;
  default_amplitude = 1.0f;
  default_offset = 0.0f;
  default_phase = 0.0f;
  amplitude = &default_amplitude;
  offset = &default_offset;
  phase = &default_phase;
}

void
Triangle::tick() {
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


Square::Square() {
  ramp = 0.0f;
  output = 0.0f;
  default_amplitude = 1.0f;
  default_offset = 0.0f;
  default_phase = 0.0f;
  amplitude = &default_amplitude;
  offset = &default_offset;
  phase = &default_phase;
}

void
Square::tick() {
  float phased_ramp;

  ramp += *frequency / sample_rate;
  ramp -= (ramp > 1.0f);
  phased_ramp = ramp + *phase;
  phased_ramp -= (phased_ramp > 1.0f);
  output = (phased_ramp < 0.5f) ? 1.0f : -1.0f;
  output = output * *amplitude + *offset;
}


Impulse::Impulse() {
  ramp = 0.0f;
  output = 0.0f;
  default_amplitude = 1.0f;
  default_offset = 0.0f;
  default_phase = 0.0f;
  amplitude = &default_amplitude;
  offset = &default_offset;
  phase = &default_phase;
}

void
Impulse::tick() {
  float phased_ramp;

  ramp += *frequency / sample_rate;
  ramp -= (ramp > 1.0f);
  phased_ramp = ramp + *phase;
  phased_ramp -= (phased_ramp > 1.0f);
  output = (ramp < last) ? 1.0f : 0.0f;
  output = output * *amplitude + *offset;
  last = ramp;
}

} // Osc

} // Segno
