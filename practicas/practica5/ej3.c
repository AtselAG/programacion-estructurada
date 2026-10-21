// Escribe una función simule el comportamiento de un dado de 6 caras. La
// función deberá regresar el valor de la cara que cae en el dado.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int simDado(int numCaras);

int main() {
  srand(time(NULL));
  printf("%d", simDado(50));

  return 0;
}

int simDado(int numCaras) { return rand() % (numCaras) + 1; }
