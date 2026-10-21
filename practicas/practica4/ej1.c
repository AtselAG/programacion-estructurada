/*2. Hacer los cambios necesarios para que el problema 2 de la Práctica 2,
conversión de unidades de temperatura, permita seleccionar en qué unidad de
medida se encuentra el valor a convertir para posteriormente preguntar a qué
unidad desea convertir dicho valor. Cada vez que se le muestre el menú de
opciones al usuario, este deberá estar validado para funcionar únicamente con
las opciones disponibles. En caso que el usuario ingrese una opción inválida, el
programa NO deberá terminar, le solicitará al usuario que seleccione una opción
correcta en el menú correspondiente. Una vez que el programa realice la
conversión, le preguntará al usuario si desea realizar otra conversión.*/

#include <stdio.h>

int main() {

  double input = 0, output = 0;
  int opt = 0, opt1 = 0;
  char flag = 0;

  do {

    do {
      printf("--Menu Conversiones--\n1.Celsius\n2.Fahrenheit\n3.Kelvin\n");
      scanf(" %d", &opt);
    } while (opt < 1 || opt > 3);

    do {
      printf("A que quieres convertirlo\n1.Celsius\n2.Fahrenheit\n3.Kelvin\n");
      scanf(" %d", &opt1);
    } while (opt1 < 1 || opt1 > 3);

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
    printf("Desea realizar otra conversion? \nIngresar n-N si desea terminar, "
           "sino, ingrese cualquier otra tecla.\n");
    scanf(" %c", &flag);
  } while (flag != 'n' && flag != 'N');
  return 0;
}