#include <stdio.h>

int main() {

  FILE *archivo = fopen("numeros", "wb");

  if (archivo != NULL) {
    int numeros[10];
    for (int i = 0; i < 10; i++) {
      numeros[i] = i + 1;
    }
    fwrite(numeros, sizeof(int), 10, archivo);
  }

  return 0;
}