#include <stdio.h>
#include <time.h>

#define NUM_PALABRAS 10
#define MAX 50
#define TOP 3

typedef struct jugador {
  char nombre[MAX];
  int tiempo;
  char palabras[NUM_PALABRAS][MAX];
} Jugador;

char char_to_upper(char letra);
int idx_ultima_letra(char cad[]);
int es_letra(char c);
int juego(char nombre[], char palabras[][MAX]);
void imprimir_estadisticas(Jugador top[], int registrados);

int main(void) {

  int opt;
  int i;
  Jugador actual;
  Jugador top[TOP];
  int registrados = 0;

  do {
    printf("----------------------------------\n"
           "*\t*\tMENÚ\t*\t*\n"
           "----------------------------------\n"
           "1) Jugar\n"
           "2) High Score\n"
           "3) Salir\n"
           "Introduzca la opción deseada: ");
    scanf("%d", &opt);

    while (getchar() != '\n')
      ;
    switch (opt) {
    case 1:

      printf("Ingresa tu nombre: ");
      scanf(" %s", actual.nombre);
      getchar();
      printf("Presiona Enter para comenzar...");
      getchar();

      actual.tiempo = juego(actual.nombre, actual.palabras);
      printf("\nJugador: %s\nTiempo: %d segundos\n\n", actual.nombre,
             actual.tiempo);
      if (registrados < TOP || actual.tiempo < top[TOP - 1].tiempo) {
        if (registrados < TOP) {
          registrados++;
        }
        i = registrados - 1;
        while (i > 0 && top[i - 1].tiempo > actual.tiempo) {
          top[i] = top[i - 1];
          i--;
        }
        top[i] = actual;
      }
      break;
    case 2:
      imprimir_estadisticas(top, registrados);
      break;
    case 3:
      printf("Vuelva pronto\n");
      break;
    default:
      printf("Opcion incorrecta\n\n");
    }
  } while (opt != 3);

  return 0;
}

char char_to_upper(char letra) {
  if (letra >= 'a' && letra <= 'z') {
    return letra - 32;
  }
  return letra;
}

int idx_ultima_letra(char cad[]) {
  int i;
  int ultima = -1;
  for (i = 0; cad[i] != '\0'; i++) {
    if (es_letra(cad[i])) {
      ultima = i;
    }
  }
  return ultima;
}

int es_letra(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int juego(char nombre[], char palabras[][MAX]) {
  int n = 0;
  int i;
  int hayNum;
  int ultima;
  char letra = ' ';
  time_t inicio;

  printf("\033[2J\033[H");
  inicio = time(NULL);

  printf("Jugador: %s\n\n", nombre);
  printf("Ingresa la primera palabra: ");
  while (n < NUM_PALABRAS) {
    scanf("%s", palabras[n]);
    hayNum = 0;
    for (i = 0; palabras[n][i] != '\0'; i++) {
      if (palabras[n][i] >= '0' && palabras[n][i] <= '9') {
        hayNum = 1;
      }
    }
    ultima = idx_ultima_letra(palabras[n]);

    if (hayNum) {
      printf("Ingresaste un numero, intenta de nuevo: ");
    } else if (n > 0 && char_to_upper(palabras[n][0]) != letra) {
      printf("Debe empezar con %c, intenta de nuevo: ", letra);
    } else {
      printf("%d. ", n + 1);
      if (n > 0) {
        printf("%c--> ", letra);
      }
      printf("%s\n", palabras[n]);

      letra = char_to_upper(palabras[n][ultima]);
      n++;
      if (n < NUM_PALABRAS) {
        printf("\nPalabra con %c: ", letra);
      }
    }
  }
  while (getchar() != '\n')
    ;
  return time(NULL) - inicio;
}

void imprimir_estadisticas(Jugador top[], int registrados) {
  int i;
  int k;

  printf("\n* * HIGH SCORE * *\n");

  for (i = 0; i < registrados; i++) {
    printf("%d. %s - %d s\n   ", i + 1, top[i].nombre, top[i].tiempo);
    for (k = 0; k < NUM_PALABRAS; k++) {
      printf("%s ", top[i].palabras[k]);
    }
    printf("\n");
  }
  printf("\n");
}
