// Escribe una función simule el comportamiento de un dado de 6 caras. La
// función deberá regresar el valor de la cara que cae en el dado.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int dado6caras(void);

int main() {

  srand(time(NULL));

  printf("%d", dado6caras());

  return 0;
}

int dado6caras(void) { return rand() % 7; }
