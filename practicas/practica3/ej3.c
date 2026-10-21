#include <stdio.h>

int main() {

  long a = 0, b = 1, c = 0, n = 0;

  printf("Ingresa n numeros de la secuencia Fibonacci: ");
  scanf("%ld", &n);

  if ((n <= 100) && (n >= 1)) {
    for (int i = 0; i < n; i++) {
      c = a + b;
      a = b;
      b = c;
      printf("%ld ", a);
    }
  } else {
    printf("Ingresa un numero valido (1-100)");
  }
  return 0;
}