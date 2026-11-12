#include "file_funcs.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SERIES 5
#define MAX_PALABRAS 5
#define MAX_CARACTERES 50
#define MAX_INTENTOS 3
#define PATH "palabras.txt"

enum elegibilidad { NO_ELEGIBLE, ELEGIBLE };

typedef struct {

  char palabra_actual[MAX_PALABRAS][MAX_CARACTERES];
  int8_t intentos;
  int8_t indice;
  int tiempo;
  int8_t elegible;
  char usuario[MAX_CARACTERES];

} Juego;

typedef struct {
  char palabras[MAX_PALABRAS][MAX_CARACTERES];
} Serie;

int addSeries(void);
void solicitarNombre(Juego *juego);
int selectRandSeries(Serie *serie);
int saveHS(Juego *juego);
int readHS(void);

int main(void) {

  int opt;
  Juego juego = {0};
  srand(time(NULL));

  do {
    printf("----------------------------------\n"
           "*\t*\tMENÚ\t*\t*\n"
           "----------------------------------\n"
           "1) Jugar\n"
           "2) Registrar serie de palabras\n"
           "3) High Score\n"
           "4) Salir\n");
    scanf("%d", &opt);

    while (getchar() != '\n')
      ;
    switch (opt) {
    case 1: {
      time_t tiempo;
      Serie serie_actual = {0};
      juego.elegible = ELEGIBLE;
      juego.intentos = 0;
      tiempo = time(NULL);
      char palabra_actual[MAX_CARACTERES];

      solicitarNombre(&juego);
      selectRandSeries(&serie_actual);

      for (int i = 1; i < MAX_PALABRAS; i++) {

        int intentos_actual = 0;
        while (intentos_actual < 3) {
          printf("\tJugador: %s | Intentos: %d\n", juego.usuario,
                 juego.intentos);
          if (i <= 1) {
            to_uppercase(serie_actual.palabras[0]);
            printf("%s\n", serie_actual.palabras[0]);
          }
          int largo = strlen(serie_actual.palabras[i]);
          to_uppercase(serie_actual.palabras[i]);
          to_uppercase(serie_actual.palabras[i - 1]);

          printf("%c", toupper(idx_primera_letra(serie_actual.palabras[i])));
          for (int j = 1; j < largo; j++) {
            printf(" _");
          }
          printf("->");
          scanf("%s", palabra_actual);
          to_uppercase(palabra_actual);
          if (!strcmp(palabra_actual, serie_actual.palabras[i])) {
            printf("correcto\n");
            break;
          } else {

            juego.intentos++;
            intentos_actual++;
            if (intentos_actual == 3) {
              juego.elegible = NO_ELEGIBLE;
              printf("\033[31mINCORRECTO\033[0m -> %s",
                     serie_actual.palabras[i]);
              break;
            }
          }
        }

        printf("\n");
      }
      juego.tiempo = time(NULL) - tiempo;
      if (juego.elegible == ELEGIBLE) {
        printf("Felicidades has ganado\n");
        saveHS(&juego);
      } else {
        printf("Jugador %s no eres elegible para High Score, su tiempo fue de "
               "%d segundos.\n",
               juego.usuario, juego.tiempo);
      }

      break;
    }
    case 2:
      printf("Registrar serie de palabras\n");
      addSeries();
      break;
    case 3:
      printf("high score\n");
      readHS();
      break;
    case 4:
      printf("Vuelva pronto :3");
      break;
    default:
      printf("Opcion incorrecta\n\n");
      break;
    }

  } while (opt != 4);

  return 0;
}

int addSeries(void) {
  Serie serie;
  FILE *file = fopen(PATH, "a");
  if (file == NULL)
    return 1;

  for (int i = 0; i < MAX_PALABRAS; i++) {
    printf("Ingresa la palabra %d: \n", i + 1);
    scanf("%s", serie.palabras[i]);
    if (i == MAX_PALABRAS - 1) {
      fprintf(file, "%s\n", serie.palabras[i]);
    } else {
      fprintf(file, "%s,", serie.palabras[i]);
    }
  }
  fclose(file);
  return 0;
}

void solicitarNombre(Juego *juego) {
  printf("Ingresa tu nombre: ");
  scanf(" %s", juego->usuario);
  getchar();
}

int selectRandSeries(Serie *serie) {
  FILE *file = fopen(PATH, "r");
  char buffer[255];
  int lines = line_count(PATH);
  int rand_line = rand() % (lines - 2) + 1;

  if (file == NULL)
    return 1;

  for (int i = 0; i < rand_line; i++) {
    fgets(buffer, sizeof(buffer), file);
    if (i + 1 == rand_line) {
      int j = 0;
      char *token = strtok(buffer, ",");
      while (token != NULL) {
        strcpy(serie->palabras[j], token);
        j++;
        token = strtok(NULL, ",\n");
      }
    }
  }
  fclose(file);
  return 0;
}

int saveHS(Juego *juego) {
  FILE *highscore = fopen("highscore.txt", "a");

  if (highscore == NULL)
    return 1;

  fprintf(highscore, "%s,%d\n", juego->usuario, juego->tiempo);
  fclose(highscore);
  return 0;
}

int readHS(void) {

  char buffer[255];
  FILE *highscore = fopen("highscore.txt", "r");
  if (highscore == NULL)
    return 1;

  while (fgets(buffer, sizeof(buffer), highscore) != NULL) {
    printf("%s", buffer);
  }
  fclose(highscore);
  return 0;
}