#include <stdio.h>

int main(){
    int n, suma = 0;

    printf("Ingresa la cantidad N de terminos impares: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Error: Ingresa un numero mayor a 0.\n");
    } else {
        printf("Los primeros %d numeros impares son:\n", n);
        
        for (int i = 1; i <= n; i++) {
            int impar = 2 * i - 1;
            printf("%d ", impar);
            suma += impar;
        }
        
        printf("\nLa suma de los %d terminos es: %d\n", n, suma);
    }

    return 0;
}