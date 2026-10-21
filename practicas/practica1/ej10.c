#include <stdio.h>

int main() {
    char departamento;
    int cantidad;
    double precioUnitario;
    double subtotal, iva, total;
    printf("Ingrese el código de departamento: ");
    scanf(" %c", &departamento);
    printf("Ingrese la cantidad de productos comprados: ");
    scanf("%d", &cantidad);
    printf("Ingrese el precio unitario del producto: ");
    scanf("%lf", &precioUnitario);
    subtotal = cantidad * precioUnitario;
    iva = subtotal * 0.16;
    total = subtotal + iva;
    printf("\n===== TICKET DE COMPRA =====\n");
    printf("Departamento\t: %c\n", departamento);
    printf("Cantidad\t: %d unidades\n", cantidad);
    printf("Precio unitario\t: $%.2f\n", precioUnitario);
    printf("-----------------------------\n");
    printf("Subtotal\t: $%.2f\n", subtotal);
    printf("IVA (16%%)\t: $%.2f\n", iva);
    printf("Total\t\t: $%.2f\n", total);

    return 0;
}