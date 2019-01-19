#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getchars(int n) {
  char *buf = malloc(sizeof(char) * n);
  int c;
  for (int i = 0; i < n; i++) {
    c = getchar();
    buf[i] = (char)c;
    if (c == EOF) {
      break;
    }
  }
  return buf;
}

int main() {
  printf("qwqwee: %s", "qwe");
  char *cols_str = getenv("COLUMNS");
  printf("qwe: %s", cols_str);
  int cols = strtol(cols_str, NULL, 10);
  const int rows = 32;
  const int ratio = 256 / rows;
  
  while (1) {
    char *in = getchars(cols);
    for (int r = rows - 1; 0 <= r; r--) {
      for (int c = 0; c < cols; c++) {
        int x = in[c];
        if (x == EOF) {
          goto end;
        }
        if ((x / ratio) == r) {
          putchar('-');
        } else {
          putchar(' ');
        }
      }
      putchar('\n');
    }
    free(in);
  }
  end:
  ;
}