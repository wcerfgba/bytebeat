#include <stdio.h>
#define PIXELS 25

int main() {
  char row[16];
  while (scanf("%16c", row) != EOF) {
    for (int i = 0; i < PIXELS; i++) {
      for (int col = 0; col < 16; col++) {
        for (int j = 0; j < 2 * PIXELS; j++) {
          printf("%c", row[col]);
        }
      }
    }
  }
}
