/* Phase-to-Amplitude Converters. */

#include <vector>
#include <cmath>

#include "segno_core.hh"
#include "segno_pac.hh"

namespace Segno {

namespace PAC {

void
Sine::tick() {
  output = sin(2 * M_PI * *ramp);
}

void
Saw::tick() {
  if (*ramp < 0.5f)
    output = 2 * *ramp;
  else
    output = 2 * *ramp - 2;
}

void
Triangle::tick() {
  if (*ramp < 0.25)
    output = 4 * *ramp;
  else if (*ramp >= 0.75)
    output = 4 * *ramp - 4;
  else
    output = 4 * (0.5f - *ramp);
}

void
Square::tick() {
  output = (*ramp < 0.5f) ? 1.0f : -1.0f;
}

void
Impulse::tick() {
  output = (*ramp < last) ? 1.0f : 0.0f;
  last = *ramp;
}

} // PAC

} // Segno
