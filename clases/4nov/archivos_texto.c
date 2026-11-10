#include <stdio.h>

int line_count(FILE *file);

int main() {
  FILE *file = fopen("testo.txt", "r");

  int lineas = line_count(file);
  printf("Lineas: %d", lineas);

  fclose(file);

  return 0;
}

int line_count(FILE *file) {

  int lines;
  char cadena[255];
  file = fopen("testo.txt", "r");

  if (file != NULL) {
    while (fgets(cadena, sizeof(cadena), file) != NULL) {
      lines++;
    }
  } else {
    printf("Error de apertura");
  }

  fclose(file);
  return lines;
}