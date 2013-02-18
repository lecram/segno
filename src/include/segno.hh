/* Segno. */

namespace Segno {

int sample_rate = 48000;

class Vertex {
 public:
  virtual void tick() {}
  virtual ~Vertex() {}
};

class Graph {
  std::vector<Vertex*> vertices;
 public:
  void add(Vertex* vertex) {
    vertices.push_back(vertex);
  }
  void tick() {
    std::vector<Vertex*>::iterator vertex;
    for (vertex = vertices.begin(); vertex != vertices.end(); vertex++)
      (**vertex).tick();
  }
  void pulse(float duration) {
    int samples, i;

    samples = duration * sample_rate;
    for (i = 0; i < samples; i++)
      tick();
  }
};

#include "segno_op.hh"
#include "segno_dl.hh"
#include "segno_pa.hh"
#include "segno_pac.hh"
#include "segno_osc.hh"
#include "segno_fx.hh"

} // Segno
