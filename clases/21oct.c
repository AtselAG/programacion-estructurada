#include <stdio.h>
#include <string.h>

typedef struct rectangulo {
  float base;
  float altura;
  float area;
  float perimetro;
  char caracter;
} Rectangulo;

typedef struct alumno {

  int matricula;
  int parcial1;
  int parcial2;
  int parcial3;

} Alumno;

float calcArea(Rectangulo rectangulo);
float calcPerimetro(Rectangulo rectangulo);

int main(void) {
  Rectangulo rectangulos[3];

  for (int i = 0; i < 3; i++) {
    printf("Ingresa el la base del rectangulo %d: ", i + 1);
    scanf("%f", &rectangulos[i].base);
    printf("Ingresa el la altura del rectangulo %d: ", i + 1);
    scanf("%f", &rectangulos[i].altura);
    printf("Ingresa el caracter del rectangulo %d: ", i + 1);
    // Limpia el buffer
    while (getchar() != '\n')
      ;
    scanf("%c", &rectangulos[i].caracter);

    rectangulos[0].area = calcArea(rectangulos[0]);
  }

  return 0;
}

float calcArea(Rectangulo rectangulo) {
  return rectangulo.base * rectangulo.altura;
}

float calcPerimetro(Rectangulo rectangulo) {

  return 2 * rectangulo.base + 2 * rectangulo.altura;
}
