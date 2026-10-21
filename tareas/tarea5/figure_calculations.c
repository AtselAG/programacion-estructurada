#include "figure_calculations.h"
#include <math.h>
#include <stdio.h>

float elevar(float base, int exp) {
  float resultado = 1;
  if (exp >= 0) {
    for (int i = 0; i < exp; i++) {
      resultado *= base;
    }
  } else {
    for (int i = 0; i < -exp; i++) {
      resultado *= base;
    }
    resultado = 1 / resultado;
  }
  return resultado;
}

float areaCirculo(float radio) { return pi * elevar(radio, 2); }

float circunf(float radio) { return 2 * pi * radio; }

float areaRect(float base, float altura) { return base * altura; }

float perimRect(float base, float altura) { return 2 * base + 2 * altura; }

float areaTriangulo(float base, float altura) { return base * altura / 2; }

// perimtero solo aplica para triangulos isosceles
float perTriangulo(float base, float altura) {
  return base + 2 * (sqrt(elevar(altura, 2) + elevar((base / 2), 2)));
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

int esPalindromo(int num) {

  int numVolteado = 0;
  int resto;
  int numNormalGuardado = num;
  while (num != 0) {
    resto = num % 10;
    numVolteado = numVolteado * 10 + resto;
    num /= 10;
    printf("Volteado: %d | Resto: %d | Numero: %d\n", numVolteado, resto, num);
  }

  if (numVolteado == numNormalGuardado) {
    printf("es palindoromo\n");
    return 0;
  } else {
    printf("noes palindoromo\n");
    return -1;
  }
}
