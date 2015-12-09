#include <stdio.h>
#define PIXELS 2

int main() {
  char row[512];
  while (scanf("%512c", row) != EOF) {
    for (int i = 0; i < PIXELS; i++) {
      for (int col = 0; col < 256; col++) {
        for (int j = 0; j < PIXELS; j++) {
          printf("%c%c", row[2*col], row[(2*col)+1]);
        }
      }
    }
  }
}
