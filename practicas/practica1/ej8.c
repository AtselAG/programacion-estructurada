#include <stdio.h>
int main(void)
{
	double radianes, grados;
	const double pi = 3.141592;
	printf("Ingrese la medida del ángulo en radianes: ");
	scanf("%lf", &radianes);
	grados = radianes * 180.0 / pi;
	printf("El valor en grados es: %.2f\n", grados);
	return 0;
}
