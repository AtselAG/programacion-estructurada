#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int dadoEspecial(int numCaras);
int dadoNormal(void);
int determinarGanador(int scorePlayer, int scoreCOM);
void dibujarTabla(int winsPlayer, int winsCOM, int empates);
void creditos();

int main() {
  srand(time(NULL));
  int dadoelegido;
  int nCaras;
  char tecla;
  int winsPlayer = 0, winsCOM = 0, empates = 0;
  int optMenu, optDado;
  int scorePlayer, scorePC;
  do {

    printf("[1] ¡Jugar!\n"
           "[2] Ver Estadísticas\n"
           "[3] Créditos\n"
           "[4] Salir\n");
    scanf("%d", &optMenu);

    switch (optMenu) {
    case 1:
      do {
        printf(
            "Quieres jugar con un dado de normal (6 caras) o un dado especial "
            "(4-20 caras)?\n");
        printf("1. Dado Normal\n"
               "2. Dado especial\n");
        scanf("%d", &optDado);
      } while (optDado != 1 && optDado != 2);

      if (optDado == 1) {
        dadoelegido = 1;
        printf("Elegiste el dado de 6 caras\n");
      } else if (optDado == 2) {
        dadoelegido = 2;
        do {
          printf("Cantidad de caras del dado (4-20): ");
          scanf("%d", &nCaras);
        } while (!(nCaras >= 4 && nCaras <= 20));
      }
      printf("Presiona una tecla para jugar: \n");
      scanf(" %c", &tecla);

      // dado 6 caras
      if (dadoelegido == 1) {
        scorePlayer = dadoNormal();
        scorePC = dadoNormal();
        printf("Score Jugador: %d\n", scorePlayer);
        printf("Score PC: %d\n", scorePC);
      } else {
        scorePlayer = dadoEspecial(nCaras);
        scorePC = dadoEspecial(nCaras);
        printf("Score Jugador: %d\n", scorePlayer);
        printf("Score PC: %d\n", scorePC);
      }

      int ganador = determinarGanador(scorePlayer, scorePC);
      printf("\n");
      if (ganador == 1) {
        winsPlayer++;
      } else if (ganador == 0) {
        winsCOM++;
      } else {
        empates++;
      }
      break;
    case 2:
      dibujarTabla(winsPlayer, winsCOM, empates);
      break;
    case 3:
      creditos();
      break;
    default:
      printf("escribe una funcion dentro del menu chat\n");
      break;
    }
  } while (optMenu != 4);

  return 0;
}

int dadoEspecial(int numCaras) {
  int cara = rand() % (numCaras) + 1;
  return cara;
}
int dadoNormal(void) {
  int cara = rand() % 6 + 1;
  return cara;
}

int determinarGanador(int scorePlayer, int scoreCOM) {
  if (scorePlayer > scoreCOM) {
    printf("Gano el jugador\n");
    return 1;
  } else if (scoreCOM > scorePlayer) {
    printf("Gano la PC\n");
    return 0;
  } else {
    printf("Empate\n");
    return -1;
  }
}

void dibujarTabla(int winsPlayer, int winsCOM, int empates) {
  printf("Wins Player: %d\n"
         "Wins PC: %d\n"
         "Empates: %d\n",
         winsPlayer, winsCOM, empates);
}

void creditos() {

  printf("este pieza de arte de codigo fue arduamente escrito por: \n"
         "Axel Avendaño\n"
         "2026\n");
}