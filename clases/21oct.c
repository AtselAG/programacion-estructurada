#include <stdio.h>
#define max 3

// Definicion de la estructura con el sinonimo de Rectangulo
typedef struct rectangulo {
  float base;
  float altura;
  float area;
  float perimetro;
  char caracter;
} Rectangulo;

// Funciones
float calcArea(Rectangulo rectangulo);
float calcPerimetro(Rectangulo rectangulo);
void dibujarRectangulo(Rectangulo rectangulo);

// Funcion principal
int main(void) {
  Rectangulo rectangulos[max];

  for (int i = 0; i < max; i++) {
    printf("Ingresa el la base del rectangulo %d: ", i + 1);
    scanf("%f", &rectangulos[i].base);
    printf("Ingresa el la altura del rectangulo %d: ", i + 1);
    scanf("%f", &rectangulos[i].altura);
    printf("Ingresa el caracter del rectangulo %d: ", i + 1);
    while (getchar() != '\n')
      ;
    scanf("%c", &rectangulos[i].caracter);
    printf("\n");

    rectangulos[i].area = calcArea(rectangulos[i]);
    rectangulos[i].perimetro = calcPerimetro(rectangulos[i]);
  }

  for (int i = 0; i < max; i++) {
    dibujarRectangulo(rectangulos[i]);
    printf("Area: %.2f\t Perimetro: %.2f", rectangulos[i].area,
           rectangulos[i].perimetro);
    printf("\n\n");
  }

  return 0;
}

float calcArea(Rectangulo rectangulo) {
  return rectangulo.base * rectangulo.altura;
}

float calcPerimetro(Rectangulo rectangulo) {

  return 2 * rectangulo.base + 2 * rectangulo.altura;
}

void dibujarRectangulo(Rectangulo rectrangulo) {

  for (int i = 0; i < rectrangulo.altura; i++) {
    for (int j = 0; j < rectrangulo.base; j++) {
      printf("%c ", rectrangulo.caracter);
    }
    printf("\n");
  }
}