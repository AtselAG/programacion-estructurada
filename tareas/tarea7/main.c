#include "cadenas.h"
#include <stdio.h>

int main() {
  char cad1[64] = "ola";
  char cad2[64] = " worl";
  char destino[64];

  printf("Longitud de \"%s\": %d\n", cad1, mi_strlen(cad1));

  mi_strcat(cad1, cad2);
  printf("Concatenacion: %s\n", cad1);

  printf("Comparar \"abc\" y \"abd\": %d\n", mi_strcmp("abc", "abd"));
  printf("Comparar \"abc\" y \"abc\": %d\n", mi_strcmp("abc", "abc"));
  printf("Comparar \"b\" y \"a\": %d\n", mi_strcmp("b", "a"));

  mi_strcpy(destino, cad1);
  printf("Copia: %s\n", destino);

  return 0;
}
