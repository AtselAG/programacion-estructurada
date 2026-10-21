/*
   video consultado para generar numero random:
   https://www.youtube.com/watch?v=Ogo_DpLhQl0

   pagina consultada para el rango:
   https://www.geeksforgeeks.org/c/generating-random-number-range-c/ */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  srand(time(NULL));

  int min = 1;
  int max = 50;
  int num_guessed = 0;
  int rand_num = rand() % (max - min + 1) + min;

  // Find the random number in the range [min, max]
  // int rd_num = rand() % (max - min + 1) + min;

  while (num_guessed != rand_num) {
    printf("Adivina el numero aleatorio entre el 1-50: ");
    scanf("%d", &num_guessed);
    if (num_guessed > rand_num) {
      printf("El numero es menor al ingresado.\n");
    } else if (num_guessed < rand_num) {
      printf("El numero es mayor al ingresado\n");
    } else {
      printf("felicidades lo adivinastes :3");
    }
  }

  return 0;
}