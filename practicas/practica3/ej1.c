#include <stdio.h>

int main() {

  float pow, n, resultado = 1;

  printf("Ingresa un numero: ");
  scanf("%f", &n);
  printf("Ahora ingresa la potencia que quieres calcular: ");
  scanf("%f", &pow);
  if (pow >= 0) {
    for (int i = 0; i < pow; i++) {
      resultado = resultado * n;
    }
  } else {
    for (int i = 0; i < -pow; i++) {
      resultado *= n;
    }
    resultado = 1 / resultado;
  }
  printf("El resultado es de: %f \n", resultado);
  return 0;
}