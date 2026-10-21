/*2. Escriba un programa en C que lea 3 números reales. Posteriormente el
programa le solicitará al usuario que ingrese en qué orden los quiere mostrar
mediante un pequeño menú de opciones, donde la opción 1 será para mostrar los
números en orden ascendente y la opción 2 será para mostrar los números en orden
descendente.*/

#include <stdio.h>

int main() {

  float a, b, c, temp, temp1, temp2;
  int opt = 0;

  printf("Ingresa 3 numeros en la misma linea, deja un espacio de separacion "
         "entre numeros: ");
  scanf("%f %f %f", &a, &b, &c);

  printf(
      "Ingresa la opcion deseada\n1.Orden Ascendente\n2.Orden Descendente\n");
  scanf("%d", &opt);

  switch (opt) {
  case 1:
    if (a > b) {
      temp = a;
      a = b;
      b = temp;

      if (c < a) {
        temp = a;
        temp1 = b;
        temp2 = c;
        b = temp;
        c = temp1;
        a = temp2;
        printf("%.2f %.2f %.2f", a, b, c);

      } else if (c < b) {
        temp = b;
        b = c;
        c = temp;
        printf("%.2f %.2f %.2f", a, b, c);
      }
      // printf("%.2f %.2f %.2f\n", a, b, c);
    } else if (b > c) {
      temp = c;
      c = b;
      b = temp;
      printf("%.2f %.2f %.2f", a, b, c);
    } else {
      printf("%.2f %.2f %.2f", a, b, c);
    }
    break;

  case 2:
    if (a > b) {
      temp = a;
      a = b;
      b = temp;
      printf("%.2f %.2f %.2f\n", c, b, a);

      if (c < a) {
        temp = a;
        temp1 = b;
        temp2 = c;
        b = temp;
        c = temp1;
        a = temp2;
        printf("%.2f %.2f %.2f", c, b, a);

      } else if (c < b) {
        temp = b;
        b = c;
        c = temp;
        printf("%.2f %.2f %.2f", c, b, a);
      }
    } else if (b > c) {
      temp = c;
      c = b;
      b = temp;
      printf("%.2f %.2f %.2f", c, b, a);
    } else {
      printf("%.2f %.2f %.2f", c, b, a);
    }
    break;

  default:
    printf("Ingresa una opcion valida");
  }

  return 0;
}
