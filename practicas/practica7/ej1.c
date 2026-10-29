#include <stdio.h>

char char_to_upper(char letra);

int main(void) {

  char letra;

  printf("Ingresa la letra a convertir: ");
  scanf(" %c", &letra);

  printf("En mayuscula: %c\n", char_to_upper(letra));

  return 0;
}

char char_to_upper(char letra) {
  if (letra >= 'a' && letra <= 'z') {
    return letra - 32;
  }
  return letra;
}
