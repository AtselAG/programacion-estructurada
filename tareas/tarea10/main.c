/*★ (Tarea) Escribe una función que regrese una línea específica de
un archivo de texto la cual deberá ser indicada por el usuario.*/

#include <stdio.h>

#define PATH "file.txt"

int line_count(FILE *file);
int pointToLine(FILE *file, int lines, int line);

int main() {

  FILE *file = fopen(PATH, "r");
  int selected_line;

  if (file != NULL) {
    int lineas = line_count(file);
    printf("Que linea quieres acceder?(1-%d): ", lineas);
    scanf("%d", &selected_line);
    if (pointToLine(file, lineas, selected_line) == 1) {
      printf("Ingresa una linea valida dentro del rango (1-%d)\n", lineas);
    }
  } else {
    printf("Error de apertura");
  }

  fclose(file);
  return 0;
}

int line_count(FILE *file) {

  int lines = 0;
  char cadena[255];
  rewind(file);
  while (fgets(cadena, sizeof(cadena), file) != NULL) {
    lines++;
  }

  return lines;
}

int pointToLine(FILE *file, int lines, int line) {

  char cadena[255];
  rewind(file);
  if (line > lines || line <= 0) {
    return 1;
  }

  for (int i = 0; i < line; i++) {
    fgets(cadena, sizeof(cadena), file);
    if (i + 1 == line) {
      printf("%s", cadena);
    }
  }
  return 0;
}