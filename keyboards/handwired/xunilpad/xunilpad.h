#pragma once
#include "quantum.h"


// The first section contains all of the arguments
// The second converts the arguments into a two-dimensional array
#define LAYOUT_pad( \
  k00, k01, k02, \
  k10, k11, k12,      \
  k20, k21, k22, k23,  \
  k30, k31, k32, k33,   \
  k40, k41, k42, k43  \
) \
{ \
  {k00, k01, k02, KC_NO}, \
  {k10, k11, k12, KC_NO}, \
  {k20, k21, k22, k23}, \
  {k30, k31, k32, k33}, \
  {k40, k41, k42, k43} \
}

/*  matrix layout
   * ,-------------------.
   * | 00 | 01 | 02 |    |
   * |----|----|----|----|
   * | 10 | 11 | 12 |    |
   * |----|----|----|----|
   * | 20 | 21 | 22 | 23 |
   * |----|----|----|----|
   * | 30 | 31 | 32 | 33 |
   * |----|----|----|----|
   * | 40 | 41 | 42 | 43 |
   * `-------------------'
 */


