#include <stdio.h>
#include <time.h>

int main(void) {
    int diaNac, mesNac, anioNac;

    printf("Escribe el dia que naciste: ");
    scanf("%d", &diaNac);
    printf("Escribe el mes en el que naciste: ");
    scanf("%d", &mesNac);
    printf("Escribe el año en el que naciste: ");
    scanf("%d", &anioNac);

    time_t t = time(NULL);
    struct tm *hoy = localtime(&t);
    int diaAct  = hoy->tm_mday;
    int mesAct  = hoy->tm_mon + 1;
    int anioAct = hoy->tm_year + 1900;


    int diasVividos = ((anioAct - anioNac) * 365.25
                           + (mesAct - mesNac) * (365.25/12)
                           + (diaAct - diaNac));

    printf("Has vivido %d días\n", diasVividos);

    return 0;
}