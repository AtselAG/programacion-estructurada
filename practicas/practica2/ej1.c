#include <stdio.h>

int main() {

  int calificacion = 0;
  printf("Ingresa tu calificacion de 0-100: ");
  if (scanf("%d", &calificacion) != 1 || calificacion < 0 ||
      calificacion > 100) {
    printf("Ingresa una calificacion valida dentro del rango.");
    return 1;
  }

  if (calificacion <= 59) {
    printf("Insuficiente\n");
    printf("Hay que estudiar mas");
  } else if (calificacion > 59 && calificacion <= 69) {
    printf("Suficiente");
  } else if (calificacion > 69 && calificacion <= 79) {
    printf("Bien");
  } else if (calificacion > 79 && calificacion <= 89) {
    printf("Muy bien");
  } else if (calificacion > 89 && calificacion < 100) {
    printf("Excelente");
  } else {
    printf("Excelente\nCalificacion Perfecta! gud job :3");
  }

  return 0;
}