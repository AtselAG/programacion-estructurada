#include <stdio.h>

int idx_ultima_letra(char cad[]);

int main(void) {

  char cadena[100];
  int pos;

  printf("Ingresa una cadena: ");
  scanf(" %99[^\n]", cadena);

  pos = idx_ultima_letra(cadena);
  printf("La ultima letra esta en la posicion %d\n", pos);

  return 0;
}

int idx_ultima_letra(char cad[]) {
  int i;
  int ultima = -1;
  for (i = 0; cad[i] != '\0'; i++) {
    if ((cad[i] >= 'a' && cad[i] <= 'z') || (cad[i] >= 'A' && cad[i] <= 'Z')) {
      ultima = i;
    }
  }
  return ultima;
}
