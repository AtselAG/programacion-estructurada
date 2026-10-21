// calificacion 15 alumnos
// hacer funcion para calcular el promedio

#include <stdio.h>
2 float calularProm(float calificacion[]);

int main() {

  float calificacion[15];

  for (int i = 0; i < 15; i++) {
    printf("Ingresa la calificacion del alumnno %d: ", i + 1);
    scanf("%f", &calificacion[i]);
  }

  printf("%f", calcularProm(calificacion[15]));

  return 0;
}

float calcularProm(float calificacion[]) {
  float total = 0;
  for (int i = 0; i < 15; i++) {
    total += calificacion[i];
  }
  return total / 15;
}