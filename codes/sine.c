#include <math.h>

float sawtooth(float x) {
  return fmod(x, 1);
}

float triangle(float x) {
  return 2.0 * fabs(sawtooth(x) - 0.5);
}

float sine(float x) {
  return 0.5 * (1.0 + cos(2.0 * 3.14159 * sawtooth(x)));
}

int unit2byte(float x) {
  return floor(256.0 * x);
}

float byte2unit(int x) {
  return x / 256.0;
}

int out(int t) {
  return unit2byte(sine(byte2unit(t)));
}

int main() {
  for (int t = 0; ; t++) {
    putchar(out(t));
  }
}