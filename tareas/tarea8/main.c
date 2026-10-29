#include <stdio.h>
#define num_alumnos 10

typedef struct alumno {
  int matricula;
  int parciales[3];
} Alumno;

int main() {

  Alumno alumnos[num_alumnos] = {0};
  int opt, contAlumno = 0, matricula;

  do {
    printf("[1] Capturar Calificaciones\n"
           "[2] Mostrar Calificaciones del Grupo\n"
           "[3] Mostrar Calificaciones de un Alumno\n"
           "[4] Salir\n");
    scanf("%d", &opt);

    switch (opt) {
    case 1:
      if (contAlumno > 9) {
        printf("Ya no se puede almacenar mas alumnos.\n");
        break;
      }
      printf("Ingresa la matricula del alumno: ");
      while (getchar() != '\n')
        ;
      scanf("%d", &alumnos[contAlumno].matricula);
      for (int i = 1; i < 4; i++) {
        printf("Ingresa la calificaion del parcial %d: ", i);
        scanf("%d", &alumnos[contAlumno].parciales[i - 1]);
      }
      printf("\n");
      contAlumno++;
      break;
    case 2:
      for (int i = 0; i < num_alumnos; i++) {
        printf("| Matricula: %d \t Parcial 1: %2d \t Parcial 2: %d \t Parcial "
               "3: %d |",
               alumnos[i].matricula, alumnos[i].parciales[0],
               alumnos[i].parciales[1], alumnos[i].parciales[2]);
        printf("\n");
      }
      break;
    case 3:
      printf("Ingresa la matricula del alumno: ");
      scanf("%d", &matricula);
      for (int i = 0; i < 10; i++) {
        if (matricula == alumnos[i].matricula) {
          printf(
              "| Matricula: %d \t Parcial 1: %2d \t Parcial 2: %d \t Parcial "
              "3: %d |",
              alumnos[i].matricula, alumnos[i].parciales[0],
              alumnos[i].parciales[1], alumnos[i].parciales[2]);
          printf("\n");
        }
      }

      printf("\n");
      break;
    case 4:
      break;
    default:
      printf("Ingresa una opcion valida dentro del menu\n");
    }
  } while (opt != 4);

  return 0;
}
