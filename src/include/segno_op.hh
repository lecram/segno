/* Basic Operators. */

namespace Op {

class Add: public Vertex {
 public:
  Add() : output(0.0f) {}
  float *a;
  float *b;
  float output;
  void tick() {
    output = *a + *b;
  }
};

class Mul: public Vertex {
 public:
  Mul() : output(0.0f) {}
  float *a;
  float *b;
  float output;
  void tick() {
    output = *a * *b;
  }
};

} // Op
