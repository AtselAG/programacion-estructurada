#include "figure_calculations.h"
#include <stdio.h>

int main(void) {

  int opt;

  float radio, altura, base;

  do {
    printf("[1] Calcular área de un círculo\n"
           "[2] Calcular área de un rectángulo\n"
           "[3] Calcular área de un triangulo\n"
           "[4] Calcular circunferencia de un círculo\n"
           "[5] Calcular perímetro de un rectángulo\n"
           "[6] Calcular perímetro de un triangulo\n"
           "[7] Salir\n");
    scanf("%d", &opt);
    switch (opt) {
    case 1:
      printf("Area Circulo\n");
      radio = validarRadio();
      printf("Area del circulo: %f\n", areaCirculo(radio));
      break;
    case 2:
      printf("Area de un rectangulo\n");
      altura = validarAltura();
      base = validarBase();
      printf("Area del rectangulo: %f\n", areaRect(base, altura));
      break;
    case 3:
      printf("Area Triangulo\n");
      altura = validarAltura();
      base = validarBase();
      printf("Area del triangulo: %f\n", areaTriangulo(base, altura));
      break;
    case 4:
      printf("Circunferencia\n");
      radio = validarRadio();
      printf("Circunferencia/Perimetro del circulo: %f\n", circunf(radio));
      break;
    case 5:
      printf("Perimetro Rectangulo\n");
      base = validarBase();
      altura = validarAltura();
      printf("Perimetro del rectangulo: %f\n", perimRect(base, altura));
      break;
    case 6:
      printf("Perimetro Triangulo\n");
      base = validarBase();
      altura = validarAltura();
      printf("Perimetro del triangulo: %f\n", perTriangulo(base, altura));
      break;
    default:
      break;
    }
  } while (opt != 7);
  printf("BAI ;333");

  return 0;
}