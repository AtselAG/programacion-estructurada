#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DADO_NORMAL 6
#define MIN_CARAS 4
#define MAX_CARAS 20

#define JUGADOR 1
#define PC 0
#define EMPATE -1

int lanzarDado(int caras);
int determinarGanador(int jugador, int pc);
void jugar(int *victoriasJugador, int *victoriasPC, int *empates);
void mostrarEstadisticas(int victoriasJugador, int victoriasPC, int empates);
void mostrarCreditos(void);
void limpiarEntrada(void);

int main(void) {
  srand(time(NULL));

  int opcion;
  int victoriasJugador = 0;
  int victoriasPC = 0;
  int empates = 0;

  do {
    printf("\n===== JUEGO DE DADOS =====\n");
    printf("[1] Jugar\n");
    printf("[2] Ver estadisticas\n");
    printf("[3] Creditos\n");
    printf("[4] Salir\n");
    printf("Opcion: ");
    scanf("%d", &opcion);

    switch (opcion) {
    case 1:
      jugar(&victoriasJugador, &victoriasPC, &empates);
      break;

    case 2:
      mostrarEstadisticas(victoriasJugador, victoriasPC, empates);
      break;

    case 3:
      mostrarCreditos();
      break;

    case 4:
      printf("\nGracias por jugar.\n");
      break;

    default:
      printf("\nOpcion invalida.\n");
    }

  } while (opcion != 4);

  return 0;
}

int lanzarDado(int caras) { return rand() % caras + 1; }

int determinarGanador(int jugador, int pc) {
  if (jugador > pc)
    return JUGADOR;

  if (pc > jugador)
    return PC;

  return EMPATE;
}

void jugar(int *victoriasJugador, int *victoriasPC, int *empates) {
  int opcionDado;
  int caras;
  int jugador;
  int pc;
  int ganador;

  do {
    printf("\n===== SELECCION DE DADO =====\n");
    printf("[1] Dado normal (6 caras)\n");
    printf("[2] Dado especial (4-20 caras)\n");
    printf("Opcion: ");
    scanf("%d", &opcionDado);

  } while (opcionDado != 1 && opcionDado != 2);

  if (opcionDado == 1) {
    caras = DADO_NORMAL;
  } else {
    do {
      printf("Numero de caras (4-20): ");
      scanf("%d", &caras);

    } while (caras < MIN_CARAS || caras > MAX_CARAS);
  }

  jugador = lanzarDado(caras);
  pc = lanzarDado(caras);

  printf("\nJugador: %d\n", jugador);
  printf("PC:      %d\n", pc);

  ganador = determinarGanador(jugador, pc);

  switch (ganador) {
  case JUGADOR:
    printf("Gano el jugador.\n");
    (*victoriasJugador)++;
    break;

  case PC:
    printf("Gano la PC.\n");
    (*victoriasPC)++;
    break;

  case EMPATE:
    printf("Empate.\n");
    (*empates)++;
    break;
  }
}

void mostrarEstadisticas(int victoriasJugador, int victoriasPC, int empates) {
  printf("\n===== ESTADISTICAS =====\n");
  printf("Jugador: %d victorias\n", victoriasJugador);
  printf("PC:      %d victorias\n", victoriasPC);
  printf("Empates: %d\n", empates);
}

void limpiarEntrada(void) {
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

void mostrarCreditos(void) {
  printf("\n===== CREDITOS =====\n");
  printf("Codigo escrito por:\n");
  printf("Axel Avendano\n");
  printf("2026\n");
}