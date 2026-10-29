#include "str_funcs.h"

char aMayus(char letra) {
  if (letra >= 'A' && letra <= 'Z') {
    return 0;
  } else if (letra >= 'a' && letra <= 'z') {
    return letra - 32;
  } else {
    return -1;
  }
}

char ultimoChar(char palabra[]) { return palabra[mi_strlen(palabra) - 1]; }

int mi_strlen(const char *cad) {
  int n = 0;
  // Avanza hasta encontrar el fin de cadena
  while (cad[n] != '\0') {
    n++;
  }
  return n;
}
int idx_ultima_letra(const char *cad) {
  int n = 0;
  // Avanza hasta encontrar el fin de cadena
  while (cad[n] != '\0') {
    n++;
  }
  return n + 1;
}

char *mi_strcat(char *dest, const char *orig) {
  int i = mi_strlen(dest); // Posicion del '\0' de dest, donde empieza la copia
  int j = 0;
  // Copia cada caracter de orig a partir del final de dest
  while (orig[j] != '\0') {
    dest[i++] = orig[j++];
  }
  dest[i] = '\0'; // Cierra la cadena resultante
  return dest;
}

int mi_strcmp(const char *a, const char *b) {
  int i = 0;
  // Avanza mientras los caracteres coincidan y no se llegue al final
  while (a[i] != '\0' && a[i] == b[i]) {
    i++;
  }
  // La diferencia del primer caracter distinto indica el orden
  return (unsigned char)a[i] - (unsigned char)b[i];
}

char *mi_strcpy(char *dest, const char *orig) {
  int i = 0;
  // Asigna y revisa en el mismo paso; el ciclo termina despues de copiar '\0'
  while ((dest[i] = orig[i]) != '\0') {
    i++;
  }
  return dest;
}
