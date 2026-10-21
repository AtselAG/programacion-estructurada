#include <stdio.h>

int main()
{
	double celsius;
	printf("Ingrese la temperatura en Celsius:\n");
	scanf("%lf", &celsius);
	printf("Temperatura en grados Fahrenheit: %.0f\n", celsius * 9.0 / 5.0 + 32.0);
	printf("Temperatura en grados Kelvin: %.2f\n", celsius + 273.15);
	return 0;
}
