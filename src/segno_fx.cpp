/* High-level Effects. */

#include "segno_fx.hh"

namespace Segno {

namespace FX {

Flanger::Flanger() : delayline(0.1f) {
  lfo.amplitude = &lfo_amplitude;
  lfo.offset = &lfo_offset;
  delayline.delay = &lfo.output;
  fb_mul.b = &delayline.output;
  fb_add.a = &fb_mul.output;
  delayline.input = &fb_add.output;
  wet_mul.b = &delayline.output;
  mix.a = &dry_mul.output;
  mix.b = &wet_mul.output;
}

void
Flanger::plug() {
  lfo.frequency = frequency;
  fb_mul.a = feedback;
  fb_add.b = input;
  dry_mul.a = dry;
  dry_mul.b = input;
  wet_mul.a = wet;
}

void
Flanger::tick() {
  lfo_offset = *tone * -0.005 + 0.01;
  lfo_amplitude = *depth * 0.005;
  lfo.tick();
  fb_add.tick();
  delayline.tick();
  fb_mul.tick();
  dry_mul.tick();
  wet_mul.tick();
  mix.tick();
  output = mix.output;
}

} // FX

} // Segno
