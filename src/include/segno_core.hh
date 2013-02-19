/* Segno Core. */

#ifndef SEGNO_CORE_HH_
#define SEGNO_CORE_HH_

namespace Segno {

extern int sample_rate;

class Vertex {
 public:
  virtual void tick() {}
  virtual ~Vertex() {}
};

class Graph {
  std::vector<Vertex*> vertices;
 public:
  void add(Vertex* vertex);
  void tick();
  void pulse(float duration);
};

} // Segno

#endif // SEGNO_CORE_HH_
