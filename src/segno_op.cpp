/* Basic Operators. */

#include <vector>

#include "segno_core.hh"
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
