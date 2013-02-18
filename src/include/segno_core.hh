/* Segno Core. */

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
  void add(Vertex* vertex);
  void tick();
  void pulse(float duration);
};

} // Segno
