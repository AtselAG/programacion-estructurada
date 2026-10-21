#include "cadenas.h"

int mi_strlen(const char *cad) {
  int n = 0;
  while (cad[n] != '\0') {
    n++;
  }
  return n;
}

char *mi_strcat(char *dest, const char *orig) {
  int i = mi_strlen(dest);
  int j = 0;
  while (orig[j] != '\0') {
    dest[i++] = orig[j++];
  }
  dest[i] = '\0';
  return dest;
}

int mi_strcmp(const char *a, const char *b) {
  int i = 0;
  while (a[i] != '\0' && a[i] == b[i]) {
    i++;
  }
  return (unsigned char)a[i] - (unsigned char)b[i];
}

char *mi_strcpy(char *dest, const char *orig) {
  int i = 0;
  while ((dest[i] = orig[i]) != '\0') {
    i++;
  }
  return dest;
}
