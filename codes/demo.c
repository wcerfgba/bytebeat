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

int byte(int x) {
  return x % 256;
}

typedef float (*gen)(float t);
typedef struct seq_step {
  int max;
  gen gen;
} seq_step;
typedef struct seq {
  int len;
  seq_step *steps;
} seq;

void seq_play(seq s) {
  for (int t = 0; ; t++) {
    for (int n = 0; n < s.len; n++) {
      seq_step step = s.steps[n];
      if (t < step.max) {
        putchar(
          unit2byte(
            step.gen(
              byte2unit(
                byte(
                  t
                )
              )
            )
          )
        );
        goto tick;
      }
    }
    return;
    tick:
    ;
  }
}

int main() {
  seq_play((seq){
    .len = 3,
    .steps = (seq_step[]){
      (seq_step){
        .max = 10000,
        .gen = &sine
      },
      (seq_step){
        .max = 20000,
        .gen = &triangle
      },
      (seq_step){
        .max = 30000,
        .gen = &sawtooth
      }
    }
  });
}