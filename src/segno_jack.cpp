/* Client to the Jack server. */

#include <vector>

#include "segno_core.hh"
#include "segno_jack.hh"

namespace Segno {

namespace Jack {

int
Client::audioCallback(jack_nframes_t nframes,
                      audioBufVector inBufs,
                      audioBufVector outBufs) {
  unsigned int i, j, k;
  for (i = 0; i < nframes; i++) {
    for (j = 0; j < in.size(); j++) {
      in[j] = inBufs[j][i];
    }
    for (k = 0; k < vertices->size(); k++)
      (*vertices)[k]->tick();
    for (j = 0; j < out.size(); j++) {
      outBufs[j][i] = *out[j];
    }
  }
  return 0;
}

Client::Client(int inn, int outn, std::vector<Vertex*>* vertices)
 : JackCpp::AudioIO("segno", inn, outn, false) {
  reserveInPorts(inn);
  reserveOutPorts(outn);
  in.resize(inn);
  out.resize(outn);
  this->vertices = vertices;
}

} // Jack

} // Segno
