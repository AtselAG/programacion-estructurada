#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  srand(time(NULL));

  int min = 1, max = 6;
  int dado_j1 = 0, dado_j2 = 0;
  int p1_score = 0, p2_score = 0, rondas = 0;

  printf("===== CARRERA DE DADOS =====\n");
  printf("Ingresa un numero de rondas: ");
  scanf("%d", &rondas);
  printf("\n");
  for (int i = 1; i <= rondas; i++) {
    printf("--- Ronda %d de %d ---\n", i, rondas);

    printf("Jugador 1 lanza: ");
    for (int j = 0; j < 2; j++) {
      int print_temp = rand() % (max - min + 1) + min;
      dado_j1 += print_temp;
      printf("[%d]", print_temp);
    }
    printf("-> Total J1: %d\n", dado_j1);
    printf("Jugador 2 lanza: ");
    for (int j = 0; j < 2; j++) {
      int print_temp = rand() % (max - min + 1) + min;
      dado_j2 += print_temp;
      printf("[%d]", print_temp);
    }
    printf("-> Total J2: %d\n", dado_j2);

    if (dado_j1 > dado_j2) {
      p1_score++;
      printf("-> Ganador de la ronda: Jugador 1 (+1 pt)\n");
      printf("\n");
    } else if (dado_j1 < dado_j2) {
      p2_score++;
      printf("-> Ganador de la ronda: Jugador 2 (+1 pt)\n");
      printf("\n");
    } else {
      printf("->Empate en esta ronda (Nadie suma puntos)\n");
      printf("\n");
    }

    dado_j1 = 0;
    dado_j2 = 0;
  }
  printf("================ RESUMEN FINAL ================\n"
         "Puntaje Jugador 1: %d\n"
         "Puntaje Jugador 2: %d\n",
         p1_score, p2_score);
  if (p1_score > p2_score) {
    printf("FELICDADES AL JUGADOR 1!!!\n");
  } else if (p1_score < p2_score) {
    printf("FELICIDADES AL JUGADOR 2!!!\n");
  } else {
    printf("¡LA PARTIDA TERMINÓ EN EMPATE GLOBAL!\n");
  }
  printf("===============================================");

  return 0;
}