#include <stdio.h>
/*
0から0.1刻みで，100までの和を計算するプログラム
*/
int main() {
  double sum = 0.0;
  int i;

  for (i = 0; i <= 1000; i++) {
    sum += (double)i * 0.1;
  }

  printf("Sum is %f\n", sum);

  return 0;
}
