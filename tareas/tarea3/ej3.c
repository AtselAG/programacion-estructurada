#include <stdio.h>

int main(){

    for (int tabla = 1; tabla <= 12; tabla++) {
        printf("--- Tabla del %d ---\n", tabla);
        for (int multiplicador = 1; multiplicador <= 10; multiplicador++) {
            printf("%d x %2d = %3d\n", tabla, multiplicador, tabla * multiplicador);
        }
        printf("\n");
    }

    return 0;
}