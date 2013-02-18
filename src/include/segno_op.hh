/* Basic Operators. */

namespace Segno {

namespace Op {

class Add: public Vertex {
 public:
  Add() : output(0.0f) {}
  float *a;
  float *b;
  float output;
  void tick();
};

class Mul: public Vertex {
 public:
  Mul() : output(0.0f) {}
  float *a;
  float *b;
  float output;
  void tick();
};

} // Op

} // Segno
