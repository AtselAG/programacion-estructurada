
#include <stdio.h>
#include <math.h>
#define _USE_MATH_DEFINES
double volumen_esfera(int r);

int main()
{
	double radio;
	double volumen;
	printf("Ingrese el radio de la esfera: ");
	if (scanf("%lf", &radio) != 1 || radio < 0) {
		printf("Radio invalido.\n");
		return 1;
	}

	volumen = volumen_esfera(radio);
	printf("El volumen de la esfera es de: %lfu^3\n", volumen);

	return 0;
}


double volumen_esfera(int r){
	double volumen;
	volumen=(4.0 / 3.0) * M_PI * (pow(r,3));
	return volumen;
}

double potencia(int)