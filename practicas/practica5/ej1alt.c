#include <math.h>
#include <stdio.h>

int esPalindromo(int n);

int main(void) {

  int n;
  int test;

  do {
    printf("Ingresa un numero de al menos 2 digitos: ");
    scanf("%d", &n);
  } while (n < 10);

  test = esPalindromo(n);

  printf("%d", test);

  return 0;
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
