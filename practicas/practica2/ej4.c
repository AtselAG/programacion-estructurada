/*Escriba un programa que lea la medida de los tres lados de un triángulo y si
forman un triángulo válido, indique el tipo de triángulo del que se trata, y
además, calcule y muestre su área y perímetro.*/

#include <math.h>
#include <stdio.h>

int main() {

  double l1 = 0, l2 = 0, l3 = 0, area = 0, semiperimetro = 0;

  printf("Ingresa el valor del lado 1: ");
  scanf("%lf", &l1);

  printf("Ingresa el valor del lado 2: ");
  scanf("%lf", &l2);

  printf("Ingresa el valor del lado 3: ");
  scanf("%lf", &l3);

  if (l1 <= 0 || l2 <= 0 || l3 <= 0 || l1 >= l3 + l2 || l2 >= l1 + l3 ||
      l3 >= l1 + l2) {
    printf("Ingresa un triangulo valido");
    return 1;
  }

  semiperimetro = (l1 + l2 + l3) / 2;

  area = sqrt(semiperimetro * (semiperimetro - l1) * (semiperimetro - l2) *
              (semiperimetro - l3));

  if ((l1 == l2) && (l1 == l3) && (l2 == l3)) {
    printf("Es un triangulo equilatero, todos sus lados son iguales\n");
  } else if ((l1 == l2) || (l1 == l3) || (l2 == l3)) {
    printf("Es un triangulo isosceles, dos de sus lados son iguales y el otro "
           "es distinto\n");
  } else {
    printf("Es un triangulo escaleno, todos sus lados son distintos.\n");
  }

  printf("Area: %lf\nPerimtero: %lf", area, semiperimetro * 2);

  return 0;
}