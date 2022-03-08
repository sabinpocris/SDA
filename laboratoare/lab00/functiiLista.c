/*-- functiiLista.c --*/
#include <ctype.h>
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

// primim o lista si afisam (i, i+1) cu aceasi paritate
void ex1(TLista list) {
	int index = 0;

	for ( ; list != NULL; list = list->urm, index++) {
		// mai avem perechi?
		if (list->urm == NULL) {
			return;
		}

		if (sameParity(list->info, list->urm->info)) {
			printf("(%d, %d) - %d %d\n", index, index + 1, list->info, list->urm->info);		
		}
	}
}

int ex2(TLista list, int lenght) {
	// avem 2 jumatati?
	if (lenght % 2 == 1) {
		return 0;
	}

	// keep data values here
	int values[lenght / 2];

	// storing the first half values
	for (int i = 0; i < lenght / 2; i++, list = list->urm;)
	{
		values[i] = list->info;
	}

	// checling the other half
	for (int i = 0; i < lenght / 2; i++, list = list->urm) {
		if (values[i] != list->info)
			return 0;
	}

	return 1;
}

int ex3(TLista list1, TLista list2) {
	for (; list2 != NULL; list2 = list2->urm) {
		if (list2->info == list1->info) {
			int somethingIsNotGuud = 0;
			TLista temp2 = list2;
			TLista temp1 = list1;
			
			for (; temp2 != NULL && temp1 != NULL; temp2 = temp2->urm, temp1 = temp1->urm) {
				if (temp2->info != temp1->info) {
					somethingIsNotGuud = 1;
					break;
				}
			}
			
			if (!somethingIsNotGuud) {
				return 1;
			}
		}
	}

	return 0;
}