/* Phase Accumulators. */

#include "segno_pa.hh"

namespace Segno {

namespace PA {

void
Ramp::tick() {
  output += *frequency / sample_rate;
  output -= (output > 1.0f);
}

} // PA

} // Segno
