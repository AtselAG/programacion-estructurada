/*2. Escriba un programa en C que lea 3 números reales. Posteriormente el programa le
solicitará al usuario que ingrese en qué orden los quiere mostrar mediante un pequeño
menú de opciones, donde la opción 1 será para mostrar los números en orden
ascendente y la opción 2 será para mostrar los números en orden descendente.*/

#include <stdio.h>

int main()
{

  float a, b, c, temp;
  int opt = 0;

  printf("Ingresa 3 numeros en la misma linea, deja un espacio de separacion entre numeros: ");
  scanf("%f %f %f", &a, &b, &c);

  printf("Ingresa la opcion deseada\n1.Orden Ascendente\n2.Orden Descendente\n");
  scanf("%d", &opt);

    if(a>b){
        temp=a;
        a=b;
        b = temp;
    }

    if(a>c){
        temp=a;
        a=c;
        c = temp; 
    }

    if(b>c){
        temp=b;
        b=c;
        c = temp; 
    }
    

  switch (opt){
  case 1:
    printf("%.2f %.2f %.2f\n", a, b, c);
    break;     
  case 2:
    printf("%.2f %.2f %.2f\n", c, b, a);
    break;
    default:
    printf("Ingresa una opcion valida");
    break;
}

  return 0;
}

