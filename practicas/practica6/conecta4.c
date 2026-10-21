#include <stdio.h>
#define FILAS 6
#define COLUMNAS 7

void mostrarTablero(char tabla[FILAS][COLUMNAS], char *fichaJ1, char *fichaJ2);
void vaciarTablero(char tabla[FILAS][COLUMNAS]);
int inicio(char *fichaJ1, char *fichaJ2);
int colocarFicha(char tabla[FILAS][COLUMNAS], char ficha, int posicionColumna);
int checarColumna(char tabla[FILAS][COLUMNAS], int columna);
int checarFila(char tabla[FILAS][COLUMNAS]);
int checarDiagonal(char tabla[FILAS][COLUMNAS], int posFila, int posCol);
int conecta4(char tabla[FILAS][COLUMNAS], int posFila, int posCol);

int main(void) {
  char fichaJ1, fichaJ2;
  int opt;
  int leidos;
  int columnaSelec;
  int fila;
  int jugadas;
  char tablero[FILAS][COLUMNAS];
  do {
    printf("    ====Conecta 4====\n"
           "\n"
           "\t[1] Jugar\n"
           "\t[2] Salir\n");
    scanf("%d", &opt);
    switch (opt) {
    // Inicio del juego
    case 1:
      jugadas = 0;
      do {
        vaciarTablero(tablero);
        if (!inicio(&fichaJ1, &fichaJ2)) {
          return 0;
        }
        if (fichaJ1 == fichaJ2) {
          printf("Las fichas no pueden tener la misma tecla.\n");
        }
      } while (fichaJ1 == fichaJ2);
      do {
        do {
          fila = -1;
          printf("==Turno del J1==\n");
          printf("Coloca la ficha en la una columna (1-7) o ingresa 8 para "
                 "salir.\n");
          scanf("%d", &columnaSelec);
          if (columnaSelec == 8) {
            break;
          }
          if (columnaSelec < 1 || columnaSelec > 7) {
            printf("Columna invalida, ingresa un numero del 1 al 7.\n");
          } else {
            fila = colocarFicha(tablero, fichaJ1, columnaSelec - 1);
            if (fila == -1) {
              printf("La columna esta llena, elige otra.\n");
            }
          }
        } while (fila == -1);
        if (columnaSelec == 8) {
          break;
        }
        jugadas++;
        mostrarTablero(tablero, &fichaJ1, &fichaJ2);
        if (conecta4(tablero, fila, columnaSelec - 1) == 1) {
          printf("Hay ganador\n");
          break;
        }
        if (jugadas == FILAS * COLUMNAS) {
          printf("Empate\n");
          break;
        }
        do {
          fila = -1;
          printf("==Turno del J2==\n");
          printf("Coloca la ficha en la una columna (1-7) o ingresa 8 para "
                 "salir.\n");
          leidos = scanf("%d", &columnaSelec);
          scanf("%*[^\n]");
          if (leidos == EOF) {
            columnaSelec = 8;
          } else if (leidos != 1) {
            columnaSelec = 0;
          }
          if (columnaSelec == 8) {
            break;
          }
          if (columnaSelec < 1 || columnaSelec > 7) {
            printf("Columna invalida, ingresa un numero del 1 al 7.\n");
          } else {
            fila = colocarFicha(tablero, fichaJ2, columnaSelec - 1);
            if (fila == -1) {
              printf("La columna esta llena, elige otra.\n");
            }
          }
        } while (fila == -1);
        if (columnaSelec == 8) {
          break;
        }
        jugadas++;
        mostrarTablero(tablero, &fichaJ1, &fichaJ2);
        if (conecta4(tablero, fila, columnaSelec - 1) == 1) {
          printf("Hay ganador\n");
          break;
        }
        if (jugadas == FILAS * COLUMNAS) {
          printf("Empate\n");
          break;
        }
      } while (conecta4(tablero, fila, columnaSelec - 1) != 1);

    case 2:
      break;
    default:
      printf("Opcion invalida, ingresa 1 o 2.\n");
      break;
    }
    printf("\n");

  } while (opt != 2);
  return 0;
}

int inicio(char *fichaJ1, char *fichaJ2) {
  char *fichas[2] = {fichaJ1, fichaJ2};
  int esLetra;
  for (int i = 0; i < 2; i++) {
    do {
      printf("J%d: Ingresa una letra (Aa-Zz):", i + 1);
      if (scanf(" %c", fichas[i]) == EOF) {
        return 0;
      }
      scanf("%*[^\n]");
      esLetra = (*fichas[i] >= 'A' && *fichas[i] <= 'Z') ||
                (*fichas[i] >= 'a' && *fichas[i] <= 'z');
      esLetra ? printf("Bien\n") : printf("Mal, ingresa una letra\n");
    } while (!esLetra);
  }
  return 1;
}

int conecta4(char tabla[FILAS][COLUMNAS], int posFila, int posCol) {
  if (checarColumna(tabla, posCol) || checarFila(tabla) ||
      checarDiagonal(tabla, posFila, posCol) == 1) {
    return 1;
  } else {
    return 0;
  }
}

int checarColumna(char tabla[FILAS][COLUMNAS], int columna) {
  char arreglo[FILAS];
  int contadorFichas = 1;
  for (int i = 0; i < FILAS; i++) {
    arreglo[i] = tabla[FILAS - 1 - i][columna];
  }
  for (int i = 0; i < FILAS - 1; i++) {
    if (arreglo[i] == arreglo[i + 1] && arreglo[i] != ' ') {
      contadorFichas++;
    } else {
      contadorFichas = 1;
    }
    if (contadorFichas == 4) {
      return 1;
    }
  }
  return 0;
}

int checarFila(char tabla[FILAS][COLUMNAS]) {
  int contadorFichas = 1;
  for (int i = 0; i < FILAS; i++) {
    contadorFichas = 1;
    for (int j = 0; j < COLUMNAS - 1; j++) {
      if (tabla[i][j] == tabla[i][j + 1] && tabla[i][j] != ' ') {
        contadorFichas++;
      } else {
        contadorFichas = 1;
      }
      if (contadorFichas == 4) {
        return 1;
      }
    }
  }
  return 0;
}

int checarDiagonal(char tabla[FILAS][COLUMNAS], int posFila, int posCol) {

  int contadorFichas;
  int fila, columna;
  char ficha = tabla[posFila][posCol];

  contadorFichas = 1;
  fila = posFila - 1;
  columna = posCol - 1;
  while (fila >= 0 && columna >= 0 && tabla[fila][columna] == ficha) {
    contadorFichas++;
    fila--;
    columna--;
  }
  fila = posFila + 1;
  columna = posCol + 1;
  while (fila < FILAS && columna < COLUMNAS && tabla[fila][columna] == ficha) {
    contadorFichas++;
    fila++;
    columna++;
  }
  if (contadorFichas >= 4) {
    return 1;
  }

  contadorFichas = 1;
  fila = posFila + 1;
  columna = posCol - 1;
  while (fila < FILAS && columna >= 0 && tabla[fila][columna] == ficha) {
    contadorFichas++;
    fila++;
    columna--;
  }
  fila = posFila - 1;
  columna = posCol + 1;
  while (fila >= 0 && columna < COLUMNAS && tabla[fila][columna] == ficha) {
    contadorFichas++;
    fila--;
    columna++;
  }
  if (contadorFichas >= 4) {
    return 1;
  }
  return 0;
}

void mostrarTablero(char tabla[FILAS][COLUMNAS], char *fichaJ1, char *fichaJ2) {
  for (int i = 0; i < FILAS; i++) {
    for (int j = 0; j < COLUMNAS; j++) {
      if (tabla[i][j] == *fichaJ1) {
        printf("[ \033[31m%c\033[0m ]", tabla[i][j]);
      } else if (tabla[i][j] == *fichaJ2) {
        printf("[ \033[33m%c\033[0m ]", tabla[i][j]);
      } else {
        printf("[ %c ]", tabla[i][j]);
      }
    }
    printf("\n");
  }
}

void vaciarTablero(char tabla[FILAS][COLUMNAS]) {
  for (int i = 0; i < FILAS; i++) {
    for (int j = 0; j < COLUMNAS; j++) {
      tabla[i][j] = ' ';
    }
  }
}

int colocarFicha(char tabla[FILAS][COLUMNAS], char ficha, int posicionColumna) {
  int fila = FILAS - 1;
  for (int i = 0; i < FILAS; i++) {
    if (tabla[FILAS - 1 - i][posicionColumna] != ' ')
      fila--;
  }
  if (fila < 0) {
    return -1;
  }
  tabla[fila][posicionColumna] = ficha;
  printf("Ficha colocada en la columna %d, y fila %d\n", posicionColumna + 1,
         fila + 1);
  return fila;
}
