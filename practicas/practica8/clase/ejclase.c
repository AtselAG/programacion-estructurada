/*Elabora un programa en C que le permita al usuario guardar una lista de
compras en un archivo de texto llamado compras.txt. El programa deberá abrir el
archivo y agregar al final los productos ingresados por el usuario, el programa
terminará cuando el usuario ingrese la palabra “Salir”. En caso de que el
archivo no exista, deberá crearlo automáticamente.*/

#include <stdio.h>
#include <string.h>

int main() {

  FILE *lista = fopen("compras.txt", "a");
  char producto[255];

  while (1) {
    if (lista != NULL) {
      printf("Escribe un producto para agregar (escribe "
             "salir"
             " para cerrar el programa): ");
      scanf("%s", producto);
      if (!strcmp(producto, "salir") || !strcmp(producto, "Salir") ||
          !strcmp(producto, "SALIR")) {
        break;
      }
      fprintf(lista, "%s\n", producto);
    }
  }
  fclose(lista);

  return 0;
}