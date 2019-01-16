int out(int t) {
  return t;
}

int main() {
  for (int t = 0; ; t++) {
    putchar(out(t));
  }
}