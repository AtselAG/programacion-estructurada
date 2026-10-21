

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define min 1
#define max 6

int main() {

  srand(time(NULL));

  int cara_pirinola = 0, fichas_jugador = 0, fichas_com = 0,
      fichas_en_juego = 0;
  int flag = 0;
  char tecla;

  do {
    printf("Cuantas fichas tienes: ");
    scanf("%d", &fichas_jugador);
  } while (fichas_jugador <= 0);

  fichas_com = fichas_jugador;
  fichas_jugador--;
  fichas_com--;
  fichas_en_juego += 2;

  do {
    printf("Escribe cualquier letra y presiona Enter para girar: ");
    scanf(" %c", &tecla);
    cara_pirinola = rand() % (max - min + 1) + min;

    switch (cara_pirinola) {
    case 1:
      printf("1.Coloca una ficha\n");
      if (fichas_jugador == 0) {
        flag = 1;
        printf("Usted se ha quedado sin fichas, fin del juego :p\n");
      } else {
        fichas_jugador--;
        fichas_en_juego++;
      }

      break;
    case 2:
      printf("2.Coloca dos fichas\n");
      if (fichas_jugador < 2) {
        flag = 1;
        printf("Usted se ha quedado sin fichas, fin del juego :p\n");
      } else {
        fichas_jugador -= 2;
        fichas_en_juego += 2;
      }
      break;
    case 3:
      printf("3.Todos colocan ficha\n");
      if (fichas_jugador > 0 && fichas_com > 0) {
        fichas_com--;
        fichas_jugador--;
        fichas_en_juego += 2;
      } else {
        flag = 1;
      }
      break;
    case 4:
      printf("4.Toma una ficha\n");
      if (fichas_en_juego > 0) {
        fichas_jugador++;
        fichas_en_juego--;
      } else {
        printf("No hay fichas en juego. \n");
      }
      break;
    case 5:
      printf("5.Toma dos fichas\n");

      if (fichas_en_juego >= 2) {
        fichas_jugador += 2;
        fichas_en_juego -= 2;
      } else {
        printf("No hay suficientes fichas en juego.\n");
      }
      break;
    case 6:
      printf("6.Toma todas las fichas del juego\n");
      if (fichas_en_juego > 0) {
        fichas_jugador += fichas_en_juego;
        fichas_en_juego = 0;
      } else {
        printf("No hay fichas en juego.\n");
      }
      break;
    default:
      break;
    }
    printf("Turno de la computadora\n");
    cara_pirinola = rand() % (max - min + 1) + min;

    switch (cara_pirinola) {
    case 1:
      printf("1.Computadora ha colocado una ficha\n");
      if (fichas_com == 0) {
        flag = 1;
        printf("La computadora se ha quedado sin fichas, fin del juego :p\n");
      } else {
        fichas_com--;
        fichas_en_juego++;
      }
      break;
    case 2:
      printf("2.Computadora ha colocado dos fichas\n");
      if (fichas_com < 2) {
        printf("La computadora se ha quedado sin fichas, fin del juego :p\n");
        flag = 1;
      } else {
        fichas_com -= 2;
        fichas_en_juego += 2;
      }
      break;
    case 3:
      printf("3.Todos colocan ficha\n");
      if (fichas_com == 0 || fichas_jugador == 0) {
        flag = 1;
        printf("No hay suficientes fichas, fin del juego :p\n");
      } else {
        fichas_com--;
        fichas_jugador--;
        fichas_en_juego += 2;
      }
      break;
    case 4:
      printf("4.Computadora ha tomado una ficha\n");
      if (fichas_en_juego > 0) {
        fichas_com++;
        fichas_en_juego--;
      } else {
        printf("No hay fichas en juego. \n");
      }
      break;
    case 5:
      printf("5.Computadora ha tomado dos fichas\n");

      if (fichas_en_juego >= 2) {
        fichas_com += 2;
        fichas_en_juego -= 2;
      } else {
        printf("No hay suficientes fichas en juego.\n");
      }
      break;
    case 6:
      if (fichas_en_juego > 0) {
        fichas_com += fichas_en_juego;
        fichas_en_juego = 0;
        printf("6.Computadora ha tomado todas las fichas del juego\n");
      } else {
        printf("No hay fichas en juego.\n");
      }
      break;
    default:
      break;
    }
    printf("fichas jugador: %d\n", fichas_jugador);
    printf("fichas computadora: %d\n", fichas_com);

  } while (fichas_jugador >= 0 && fichas_com >= 0 && flag == 0);

  return 0;
}
