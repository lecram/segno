/* Basic Operators. */

#include "segno_op.hh"

namespace Segno {

namespace Op {

void
Add::tick() {
  output = *a + *b;
}

void
Mul::tick() {
  output = *a * *b;
}

} // Op

} // Segno
