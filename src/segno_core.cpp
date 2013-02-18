/* Segno. */

#include <vector>

#include "segno_core.hh"

namespace Segno {

void
Graph::add(Vertex* vertex) {
  vertices.push_back(vertex);
}

void
Graph::tick() {
  std::vector<Vertex*>::iterator vertex;
  for (vertex = vertices.begin(); vertex != vertices.end(); vertex++)
    (**vertex).tick();
}

void
Graph::pulse(float duration) {
  int samples, i;

  samples = duration * sample_rate;
  for (i = 0; i < samples; i++)
    tick();
}

} // Segno
