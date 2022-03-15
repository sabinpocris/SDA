/*-- functiiLista.c --*/
#include <ctype.h>
#include <stdio.h>
#include "tlista.h"

/*--- operatii de baza pentru lista simplu inlantuita ---*/

TLista AlocCelula(int e)          /* adresa celulei create sau NULL */
{ TLista aux = (TLista)malloc(sizeof(TCelula));  /* (1) incearca alocare */
  if (aux)                            /* aux contine adresa noii celule */
  { aux->info = e;                   /* (2,3) completeaza noua celula */
    aux->urm = NULL;
  }
  return aux;             /* rezultatul este adresa noii celule sau NULL */
}

void AfisareL(TLista L)
       /* afiseaza valorile elementelor din lista */
{
  printf("Lista: [");                      /* marcheaza inceput lista */
  for (; L != NULL; L = L->urm)       /* pentru fiecare celula */
    printf("%d ", L->info);              /* afiseaza informatie */
  printf("]");                               /* marcheaza sfarsit lista */
}

void DistrugeL(TLista* aL)
{
  TLista aux;
  while(*aL)
  {
    aux = *aL;
    *aL = aux->urm;
    free(aux);
  }
}

// return true if they have the same parity, false otherwise
int sameParity(int nr1, int nr2) {
	// are they both even?
	if (nr1 % 2 == 0 && nr2 % 2 == 0)
		return 1;
	
	// are they both odd?
	if (nr1 % 2 == 1 && nr2 % 2 == 1)
		return 1;

	return 0;
}



TLista ex1(TLista list, int a, int b, int *count) {
    TLista tempList = NULL;
    TCelula *tempCell = NULL, *lastCell = NULL;
    *count = 0;

    while (list) {
        if (list->info < a || list->info > b) {
            list = list->urm;
        } else {
            if (tempList == NULL) {
                tempCell = AlocCelula(list->info);
                tempList = tempCell;
            } else {
                tempCell = AlocCelula(list->info);
                lastCell->urm = tempCell;
            }
            
            lastCell = tempCell;

            (*count)++;
            list = list->urm;
        }
    }


    return tempList;
}



TLista ex2(TLista *oldList, int div, int *count) {
	TLista tempList = NULL;
    TLista *list = oldList;
    TCelula *lastCell = NULL, *tempCell;
    
    for (; (*list) != NULL;) {
        if ((*list)->info % div != 0) {
            (*list) = (*list)->urm;
            continue;
        }
        
        tempCell = AlocCelula((*list)->info);

        if (tempList == NULL) {
            tempList = tempCell;
        } else {
            lastCell->urm = tempCell;

                        
        }

        lastCell = tempCell;
        (*list) = (*list)->urm;
    }


    return tempList;
}
