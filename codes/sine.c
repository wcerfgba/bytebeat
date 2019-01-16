#include <math.h>

int out(int t) {
  return floor(256.0 * 0.5 * (1.0 + cos( 2.0 * 3.14159 * abs( ((t % 256) / 256.0) ) ) ) );
}

int main() {
  for (int t = 0; ; t++) {
    putchar(out(t));
  }
}