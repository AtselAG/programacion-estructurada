#include <stdio.h>

int main() {

  int lista_alumnos[10][4];
  int opt;
  int contAlumno = 0;
  int matricula;
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
      scanf("%d", &lista_alumnos[contAlumno][0]);
      printf("%d\n", lista_alumnos[contAlumno][0]);

      for (int i = 1; i < 4; i++) {
        do {
          printf("Ingresa la calificacion del %der parcial: ", i);
          scanf("%d", &lista_alumnos[contAlumno][i]);
          if (lista_alumnos[contAlumno][i] < 0 ||
              lista_alumnos[contAlumno][i] > 100) {
            printf("Ingresa una calificacion valida\n");
          }
        } while (lista_alumnos[contAlumno][i] < 0 ||
                 lista_alumnos[contAlumno][i] > 100);
      }
      printf("\n");
      contAlumno++;
      break;
    case 2:
      for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 4; j++) {
          printf("[%d]", lista_alumnos[i][j]);
        }
        printf("\n");
      }
      break;
    case 3:
      printf("Ingresa la matricula del alumno: ");
      scanf("%d", &matricula);
      for (int i = 0; i < 10; i++) {
        if (matricula == lista_alumnos[i][0]) {
          for (int j = 0; j < 4; j++) {
            printf("[%d]", lista_alumnos[i][j]);
          }
        }
      }

      printf("\n");
      break;
    default:
      printf("Ingresa una opcion valida dentro del menu\n");
    }
  } while (opt != 4);

  return 0;
}
