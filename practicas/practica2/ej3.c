/*Del Problema: Conversión de unidades de temperatura de la práctica anterior
convierte de grados Celsius a Fahrenheit y Kelvin. Realice los cambios
necesarios para que el programa le permita al usuario especificar la unidad que
se tiene y a qué unidad desea convertir, utilizando un 1 para Celsius, 2
Fahrenheit y 3 para Kelvin. Utilice un condicional switch-case.*/

#include <stdio.h>

int main() {

  double input = 0, output = 0;
  int opt = 0, opt1 = 0;

  printf("--Menu Conversiones--\n1.Celsius\n2.Fahrenheit\n3.Kelvin\n");
  scanf(" %d", &opt);

  printf("A que quieres convertirlo\n1.Celsius\n2.Fahrenheit\n3.Kelvin\n");
  scanf(" %d", &opt1);

  switch (opt) {
  // Celsius
  case 1:
    switch (opt1) {
    // Celsius a Celsius, cancela
    case 1:
      printf("No se puede convertir, es la misma unidad.\n");
      break;
    // Celsius a Fahrenheit
    case 2:
      printf("Ingresa la temperatura en grados Celsius: ");
      scanf(" %lf", &input);
      output = (input * 9.0 / 5.0) + 32.0;
      printf("%lf Fahrenheit.\n", output);
      break;
    // Celsius a Kelvin
    case 3:
      printf("Ingresa la temperatura en grados Celsius: ");
      scanf(" %lf", &input);
      output = input + 273.15;
      printf("%lf Kelvin.\n", output);
      break;
    default:
      break;
    }
    break;

  // Fahrenheit
  case 2:
    switch (opt1) {
    // Fahrenheit a Celsius
    case 1:
      printf("Ingresa la temperatura en grados Fahrenheit: ");
      scanf(" %lf", &input);
      output = (input - 32) * 5 / 9;
      printf(" %lf Celsius.\n", output);
      break;
    // Fahrenheit a Fahrenheit, cancela
    case 2:
      printf("No se puede convertir, es la misma unidad\n");
      break;
    // Fahrenheit a Kelvin
    case 3:
      printf("Ingresa la temperatura en grados Fahrenheit: ");
      scanf(" %lf", &input);
      output = (input + 459.67) * 5 / 9;
      printf("%lf Kelvin.\n", output);
      break;
    default:
      break;
    }
    break;

  // Kelvin
  case 3:
    switch (opt1) {
    // Kelvin a Celsius
    case 1:
      printf("Ingresa la temperatura en grados Kelvin: ");
      scanf(" %lf", &input);
      output = input - 273.15;
      printf(" %lf Celsius.\n", output);
      break;
    // Kelvin a Fahrenheit
    case 2:
      printf("Ingresa la temperatura en grados Kelvin: ");
      scanf(" %lf", &input);
      output = (input * 9 / 5) - 459.67;
      printf(" %lf Fahrenheit.\n", output);
      break;
    // Kelvin a Kelvin, cancela
    case 3:
      printf("No se puede convertir, es la misma unidad\n");
      break;
    default:
      break;
    }
    break;
  default:
    printf("Opcion(es) no validas.\n");
    break;
  }
  return 0;
}