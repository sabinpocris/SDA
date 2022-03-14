/*--- testLista.c ---*/
#include <ctype.h>
#include <stdio.h>
#include "tlista.h"

TLista CitireL(int *lg) /* construieste lista cu elemente citite */
{
	TLista L = NULL, u, aux;
	int x;
	char ch;
	for (*lg = 0; scanf("%i", &x) == 1;)
	{
		aux = AlocCelula(x); /* incearca inserarea valorii citite */
		if (!aux)
			return L; /* alocare esuata => sfarsit citire */
		if (L == NULL)
			L = aux;
		else
			u->urm = aux;
		u = aux;
		(*lg)++;
	}

	while ((ch = getchar()) != EOF && ch != '\n')
		;
	return L; /* intoarce lista rezultat */
}

int main()
{
	TLista x = NULL;  /* Lista prelucrata */
	TLista tempLista = NULL;
	int lx;			 /* lungime lista */
	int exNumber = 0;

	for (;;)
	{
		/* citeste si afiseaza lista */
		printf("\nIntroduceti valori elemente terminate cu valoare nenumerica:\n");
		x = CitireL(&lx);
		// AfisareL(x);
		if (!x)
			continue;

		printf("Numar exercitiu: >");
		scanf("%d", &exNumber);

		getchar(); // flush the stdin

		switch (exNumber) {
		case 1:
			ex1(x);
			break;

		case 2:
			printf("valoare returnata: %d\n", ex2(x, lx));
			break;
		
		case 3:
			tempLista = CitireL(&lx);

			//AfisareL(tempLista);

			if (tempLista == NULL)
				break;

			printf("valoare returnata: %d\n", ex3(x, tempLista));
			break;
		}

		/* apeluri functii implementate */

		DistrugeL(&x);
		printf("\n  Inca un test ? [d/n]");
		if (getchar() == 'n')
			break;
	}
}