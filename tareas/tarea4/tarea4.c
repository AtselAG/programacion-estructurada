#include <stdio.h>
#define pi 3.141592

float calcAreaCirculo(float radio);
float calcAreaRectangulo(float a, float b);
float calcPerimetroCirculo(float radio);
float calcPerimetroRectangulo(float a, float b);
float validarRadio(void);
float validarBase(void);
float validarAltura(void);

int main() {
  int opt;
  float radio, altura, base;

  do {
    printf("[1] Calcular área de un círculo\n"
           "[2] Calcular área de un rectángulo\n"
           "[3] Calcular perímetro de un círculo\n"
           "[4] Calcular perímetro de un rectángulo\n"
           "[5] Salir\n");
    scanf("%d", &opt);
    switch (opt) {
    case 1:
      radio = validarRadio();
      printf("Area: %0.2f\n", calcAreaCirculo(radio));
      break;
    case 2:
      altura = validarAltura();
      base = validarBase();
      printf("Area: %0.2f\n", calcAreaRectangulo(base, altura));
      break;
    case 3:
      radio = validarRadio();
      printf("Circunferencia: %0.2f\n", calcPerimetroCirculo(radio));
      break;
    case 4:
      base = validarBase();
      altura = validarAltura();
      printf("Perimetro: %0.2f\n", calcPerimetroRectangulo(base, altura));
      break;
    default:
      printf("Ingresa una opcion valida (1-5)\n");
      break;
    }
  } while (opt != 5);
  printf("BAI ;333");
  return 0;
}

float calcAreaCirculo(float radio) { return pi * radio * radio; }
float calcAreaRectangulo(float base, float altura) { return base * altura; }
float calcPerimetroCirculo(float radio) { return 2 * pi * radio; }
float calcPerimetroRectangulo(float base, float altura) {
  return 2 * altura + 2 * base;
}

float validarRadio(void) {
  float radio;
  do {
    printf("ingresa el radio: ");
    scanf("%f", &radio);
    if (radio <= 0) {
      printf("Ingresa un radio valido mayor a 0.\n");
    }
  } while (radio <= 0);
  return radio;
}

float validarBase(void) {
  float base;
  do {
    printf("ingresa la base: ");
    scanf("%f", &base);
    if (base <= 0) {
      printf("Ingresa una base valida mayor a 0.\n");
    }
  } while (base <= 0);
  return base;
}

float validarAltura(void) {
  float altura;
  do {
    printf("ingresa la altura: ");
    scanf("%f", &altura);
    if (altura <= 0) {
      printf("Ingresa una altura valida mayor a 0.\n");
    }
  } while (altura <= 0);
  return altura;
}