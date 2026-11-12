#include "file_funcs.h"
#include <ctype.h>
#include <stdio.h>

int line_count(char path[]) {
  FILE *file = fopen(path, "r");
  int lines = 0;
  char cadena[255];
  rewind(file);
  while (fgets(cadena, sizeof(cadena), file) != NULL)
    lines++;
  fclose(file);
  return lines;
}

int pointToLine(char path[], int lines, int line) {
  FILE *file = fopen(path, "r");
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
  fclose(file);
  return 0;
}

int es_letra(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
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

char idx_primera_letra(char cad[]) { return cad[0]; }

void to_uppercase(char cad[]) {
  for (int i = 0; cad[i] != '\0'; i++) {
    cad[i] = toupper((unsigned char)cad[i]);
  }
}
