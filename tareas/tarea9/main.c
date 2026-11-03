/*Una vez escrito y guardado el archivo de texto, escribe un programa en C
que lea cada una de las líneas de dicho archivo y las escriba una por una
en otro archivo llamado copia_tarea9. Verificar que el contenido del
archivo original se haya copiado de forma correcta.*/

#include <stdio.h>

int main() {

  FILE *archivo;
  FILE *archivo2;
  char cadena[255];
  archivo = fopen("lista.txt", "r");

  if (archivo != NULL) {
    archivo2 = fopen("copia_tarea9.txt", "w");
    if (archivo2 != NULL) {
      while (fgets(cadena, sizeof(cadena), archivo) != NULL) {
        fputs(cadena, archivo2);
      }
      if (fclose(archivo2) == 0) {
        printf("El texto ha sido copiado correctamente.");
      } else {
        printf("Error");
      }
    } else {
      printf("Error");
    }
    fclose(archivo);
  } else {
    printf("Error");
  }
  return 0;
}
