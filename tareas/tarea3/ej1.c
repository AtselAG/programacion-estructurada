#include <stdio.h>

int main(){

  int n = 0, fact = 1;

  printf("Ingresa el numero a sacar factorial: ");
  scanf("%d", &n);
  

  for(int i=1;i<=n;i++){  
    fact *=i;
    } 
 
  printf("\nEl factorial del numero ingresado es: %d", fact);

  return 0;
}