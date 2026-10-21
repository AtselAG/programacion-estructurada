/*5. Desarrolle un programa en C que permita calcular el pago total a realizar
del servicio de luz para una casa con tarifa 1F. Para esto, se le solicitará al
usuario ingresar su consumo energético y el mes en el que se encuentran con la
finalidad de determinar si aplica tarifa de verano. La siguiente tabla muestra
el desglose de la tarifa de acuerdo a la cantidad de kWh consumidos.

TARIFA FUERA DE VERANO (NOVIEMBRE - ABRIL)

Tipo de Consumo Rango de kWh Costo por kWh
Consumo Básico Primeros 75 kWh 1.027 MXN
Consumo Intermedio Siguientes 125 kWh 1.251 MXN
Consumo Excedente Por cada kWh adicional a lo anterior 3.659 MXN

TARIFA DE VERANO (MAYO - OCTUBRE)

Consumo Básico Primeros 300 kWh 0.776 MXN
Consumo Int. Bajo Siguientes 900 kWh 0.964 MXN
Consumo Int. Alto Siguientes 1300 kWh 2.346 MXN
Consumo Excedente Por cada kWh adicional a lo anterior 3.711 MXN

El programa deberá determinar si el mes ingresado por el usuario corresponde a
tarifa de verano o fuera de verano, para posteriormente determinar el costo del
consumo energético de acuerdo a los kWh ingresados. Una vez determinado el costo
del consumo, el programa deberá realizar el cálculo total del pago a realizar,
sumando al costo del consumo el Derecho al Alumbrado Público (DAP, 15.00 MXN) y
el*/

#include <stdio.h>

int main() {

  int consumo_energetico = 0, mes = 0, DAP = 15;
  double pago = 0, pago_final = 0, costo_por_kW = 0, iva = 0.08;
  int aplica_tarifa = 0;

  printf("Ingresa el consumo energetico en kWh: ");
  scanf("%d", &consumo_energetico);
  printf("Ingresa el numero del mes (1-12): ");
  scanf("%d", &mes);

  if (mes >= 5 && mes <= 10) {
    printf("Se aplica tarifa de verano\n");
    aplica_tarifa = 1;
  } else {
    printf("No aplica tarifa de verano\n");
  }

  // Fuera del verano, no aplica tarifa
  if (consumo_energetico <= 75 && aplica_tarifa == 0) {
    costo_por_kW = 1.027;
    pago = consumo_energetico * costo_por_kW;
    pago_final = pago + (pago * iva) + DAP;
    printf("No excede el consumo basico, el costo sera de "
           "%0.3f MXN",
           pago_final);
  } else if (consumo_energetico > 75 && consumo_energetico <= 200 &&
             aplica_tarifa == 0) {
    pago = 75 * 1.027 + (consumo_energetico - 75) * 1.251;
    pago_final = pago + (pago * iva) + DAP;
    printf("Consumo intermedio, el costo sera de "
           "%0.3f MXN",
           pago_final);
  } else if (consumo_energetico > 200 && aplica_tarifa == 0) {
    pago = 75 * 1.027 + 125 * 1.251 + (consumo_energetico - 200) * 3.659;
    pago_final = pago + (pago * iva) + DAP;
    printf("Consumo Excedente, el costo sera de "
           "%0.3f MXN",
           pago_final);
  }

  // Dentro del verano, no aplica tarifa
  if (consumo_energetico <= 300 && aplica_tarifa == 1) {
    costo_por_kW = 0.776;
    pago = consumo_energetico * costo_por_kW;
    pago_final = pago + (pago * iva) + DAP;
    printf("No excede el consumo basico, el costo sera de "
           "%0.3f MXN",
           pago_final);
  } else if (consumo_energetico > 300 && consumo_energetico <= 1200 &&
             aplica_tarifa == 1) {
    pago = 300 * 0.776 + (consumo_energetico - 300) * 0.964;
    pago_final = pago + (pago * iva) + DAP;
    printf("Consumo Int. Bajo, el costo sera de "
           "%0.3f MXN",
           pago_final);
  } else if (consumo_energetico > 1200 && consumo_energetico <= 2500 &&
             aplica_tarifa == 1) {
    pago = 300 * 0.776 + 900 * 0.964 + (consumo_energetico - 1200) * 2.346;
    pago_final = pago + (pago * iva) + DAP;
    printf("Consumo Int.Alto, el costo sera de "
           "%0.3f MXN",
           pago_final);
  } else if (consumo_energetico > 2500 && aplica_tarifa == 1) {
    pago = 300 * 0.776 + 900 * 0.964 + 1200 * 2.346 +
           (consumo_energetico - 2500) * 3.711;
    pago_final = pago + (pago * iva) + DAP;
    printf("Consumo Excedente, el costo sera de "
           "%0.3f MXN",
           pago_final);
  }

  return 0;
}
