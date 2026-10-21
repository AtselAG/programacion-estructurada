/*

    'A' = Excelente
    'B' = Aprobado
    'C' = Aprobado
    'D' = Reprobado
    'F' = Reprobado

    Si numAlum es 0, volver a pedir la cantidad de alumnos
    Si la calificacion es distinta a la que se pide, volver a solicitar */

#include <stdio.h>

int main() {

  int alumExcelentes = 0, alumAprobados = 0, alumReprobados = 0, numAlum = 0;
  char calificacion;

  while (numAlum <= 0) {
    printf("Ingresa la cantidad de alumnos a evauluar: ");
    scanf("%d", &numAlum);
  }

  for (int i = 0; i < numAlum; i++) {
    do {
      printf("Ingresa la calificacion del alumno %d: \n", i);
      scanf(" %c", &calificacion);
      switch (calificacion) {
      case 'A':
        alumExcelentes++;
        break;
      case 'B':
        alumAprobados++;
        break;
      case 'C':
        alumAprobados++;
        break;
      case 'D':
        alumReprobados++;
        break;
      case 'F':
        alumReprobados++;
        break;
      default:
        printf("Ingresa una calificacion valida (A B C D o F)\n");
        break;
      }
    } while (calificacion != 'A' && calificacion != 'B' &&
             calificacion != 'C' && calificacion != 'D' && calificacion != 'F');
  }

  printf(
      "Alumnos Excelentes: %d\nAlumnos Aprobados: %d\nAlumnos Reprobados: %d",
      alumExcelentes, alumAprobados, alumReprobados);

  return 0;
}