#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void add(node *head, int x) {
  // pre:  head points to the first, empty element.
  //       The last element's next is NULL
  // post: A new node containing x is added to the end of the list
  assert(head != NULL);
  node *p = head;
  while (p->next != NULL) {
    p = p->next;
  } // p points to the last element
  node *element = malloc(sizeof(node));
  element->next = NULL;
  element->data = x;
  p->next = element;
}

// exersice 3.b
int size(node *l) {
  assert(l != NULL);                                                   /*Precondition*/
  node *p = l;                                                         /**p peger på det første element*/
  int list_size = 0;                                                   /*Tælle int der tæller list size*/
  while (p->next != NULL){                                             /*While loop der går igennem listen, og tilføjer 1 til tælleren, for hvert element*/
    p = p->next;
    list_size++;
  }

	return list_size;                                                    /*returnerer Tælle inten*/
}

// exersice 3.c and 3.d
void printout(node *l) {
  // pre:  head points to the first, empty element.
  //       The last element's next is NULL
  // post: The values of the list are printed out
  node *p = l->next;
  printf("\nListens værdier er: ");
  while (p != NULL) {                                                 /*While loop der kører igennem listen*/
    printf("%d, ", p->data);                                          /*Printer data fra første element, som ikke er head*/
    p = p->next;                                                      /*Får p til at pege på det næste element*/
  }
  printf("\n");
}

// exersice 3.e
int largest(node *l) {
  // pre:  head poinst to the first, empty element.
  // 	     The last element's next is NULL.
  // post: Returns the largest value of the list
  assert(l != NULL);                                                /*Precondition*/
  node *p = l;                                                      /**p peger på det første element*/
  int largest_val = p->data;                                        /*Int der gemmer det største elements værdi, starter med det første elements værdi*/
  while(p != NULL) {                                                /*While loop der kører igennem listen, og cheker om hver elements værdi er større end largest_val. Hvis ja gør int lig med element værdi*/
    if (p->data > largest_val) {
      largest_val = p->data;
    }
    p = p->next;
  }

  return largest_val;                                               /*Returnerer den største værdi*/
}

#ifndef TEST
int main() {
  node *list = malloc(sizeof(node));
  list->next = NULL; // create first empty element

  add(list, 1);
  add(list, 3);
  add(list, 2);
  // Show list here
  add(list, 2);
  // Show list here
 
 int list_size = size(list);                                       /*Int der kalder size, for at få værdien af listens længde*/
  printf("\nListens længde er: %d", list_size);                    /*Printer listens længde*/
  printout(list);                                                  /*Printer hele listen*/
  int largest_val = largest(list);                                 /*Int der kalder largest, for at få elementet med den største værdis værdi*/                     
  printf("Den største værdi i listen er: %d", largest_val);        /*Printer den største værdi*/

  return 0;
}

#endif
