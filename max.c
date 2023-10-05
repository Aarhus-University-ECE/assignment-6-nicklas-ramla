#include "max.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int max(int *numbers, int size) {                                           /*Funktion der finder største værdi i array*/
  assert(size>0);                                                           /*Precondition: size>0*/
  int maxval = numbers[0];                                                  /*Int der gemmer foreløbig højeste værdi*/

  for(int i = 0; i < size; i++){                                            /*For-loop der går igennem arrayen, og cheker om maxval er mindre end arrayværdien på den plads. Hvis ja, så sæt maxval lig det*/                                    
    if (numbers[i] > maxval){
      maxval = numbers[i];
    }

  }

  return maxval;                                                            /*Returnerer maxval*/
}

#ifndef TEST

int main() {
  int size;                                                            
  int seed;
  
  printf("Skriv hvor mange tal der skal være i arrayen og et tilfælidgt tal som seed til rand():\n"); 
  scanf("%d%d", &size, &seed);                                                       /*Brugeren indtaster arrayens størrelse (size>0), og et random tal som seed til tilfældighedsgenerator*/
  assert (size>0);                                                                   /*Checker precondition*/
  int numbers[size];
  srand(seed);                                                                    /*Bruger det tilfældige tal til at sætte en seed til rand()*/

  printf("\nArrayen er så:\n");                                                   /*Laver en array med længden size og tilfældige tal mellem 1-100 i hver position*/
  for (int i = 0; i < size; i++){
    numbers[i] = rand() % 100+1;
    printf("%d ", numbers[i]);
  }

  int maxval = max(&numbers, size);                                               /*Int maxval bliver givet af funktionen max*/

  printf("\nDet største tal i arrayen er: %d", maxval);                           /*Printer den højeste værdi i arrayen*/
	return 0;
}

#endif
