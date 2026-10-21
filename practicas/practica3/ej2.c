#include <stdio.h>

int main() {
  // I
  printf("I)\n");
  for (int rows = 0; rows < 4; rows++) {
    for (int columns = 0; columns < 10; columns++) {
      printf("*");
    }
    printf("*\n");
  }

  // II
  printf("\n");
  printf("II)\n");

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < i; j++) {
      printf("*");
    }
    printf("*\n");
  }

  printf("\n");
  printf("III)\n");

  // III
  for (int i = 5; i > 0; i--) {
    for (int j = 1; j < i; j++) {
      printf(" ");
    }
    for (int k = 0; k < 6 - i; k++) {
      printf("*");
    }
    printf("\n");
  }

  printf("\n");
  printf("IV)\n");

  // IV
  for (int i = 5; i > 0; i--) {
    for (int j = 1; j < i; j++) {
      printf(" ");
    }
    for (int k = 0; k < (11 - 2 * i); k++) {
      printf("*");
    }
    printf("\n");
  }

  printf("\n");
  // IV
  printf("V)\n");
  for (int i = 1; i <= 5; i++) {
    for (int j = 5; j > i; j--) {
      printf(" ");
    }
    for (int k = 0; k < 2 * i - 1; k++) {
      printf("%i", i);
    }
    printf("\n");
  }
  printf("\n");
  printf("VI)\n");

  for (int i = 1; i <= 5; i++) {
    for (int j = 5; j > i; j--) {
      printf(" ");
    }
    for (int k = i; k >= 1; k--) {
      printf("%i", k);
    }
    for (int k = 2; k <= i; k++) {
      printf("%i", k);
    }
    printf("\n");
  }
  return 0;
}