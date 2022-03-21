/*--- testListaG.c ---*/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "tlg.h"

#define MAX 3  /* număr maxim de elemente din lista */

TLG CitireL_Int()     /* construieste lista cu elemente întregi - MAX elemente */
{ TLG L = NULL, u, aux;
  int *elem, nr = 0;

  printf("\nConstructie lista generică cu %i elemente întregi\n", MAX);
  for(nr = 0; nr < MAX; nr++)
  {
    int* elem = (int*)malloc(sizeof(int));
    if(!elem) return L;

    scanf("%i", elem);

    aux = Aloc_CelulaG(elem);           /* incearca inserarea valorii citite */
    if(!aux) {	/* alocare esuata => sfarsit citire */
	free(elem); 
	return L;
    }       
       
    if(L == NULL) L = aux;
    else u->urm = aux;
    u = aux;
  }
  
  return L;                     /* intoarce lista rezultat */
}

/* construieste lista cu 
 * elemente structuri tip Book - MAX elemente 
 * */

TLG CitireL_Book() { 
    TLG L = NULL, aux;
    Book *elem;

    printf("\nConstructie lista generică cu %i elemente tip Book\n", MAX);
    for(int i = 0; i < MAX; i++) {
        elem = malloc(sizeof(Book));
        
        if (!elem) 
            return L;
        
        readBook(elem);

        aux = Aloc_CelulaG(elem);           /* incearca inserarea valorii citite */
        if(!aux) {	/* alocare esuata => sfarsit citire */
	        free(elem); 
	        return L;
        }       
       
        if (L == NULL) {
            L = aux;
        }
        else {
            insertCell(&L, aux);

        }
  }
  
    return L;                     /* intoarce lista rezultat */
}


void afi_int(void* el)
{
	printf("%i ", *(int*)el);
}

int main () { 
    TLG L = NULL;     
    int choice = 0;
 
    while (1) {
        printf("Numar exercitiu (1-2) (0 - quit): ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            L = CitireL_Int();  /* construiește lista generica cu elemente întregi */  
            
            printf("The result of isEven(): %d\n", checkListItems(L, &isEven));
            AfisareLG(L, afi_int);
            
            DistrugeLG(&L, free);
            break;
        case 2:
            L = CitireL_Book();
                        
            AfisareLG(L, afi_book);
            
            ex2B(L);
            ex2C(&L);
            
            AfisareLG(L, afi_book);

            DistrugeLG(&L, free_book);
            break;
        case 0:
            return 0;
        }
    }
}
