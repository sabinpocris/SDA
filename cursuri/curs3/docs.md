# Liste simplu inlantuite - partea 2 - 08.03.2022

## Definitie `TLista`

```c
typedef struct celula {
	int info;
	struct celula *urm;
} TCelula, *TLista;

TLista L;
```

## Inserare sfarsit lista

```c
int InsSfL(TLista *aL, int e) {
	TLista p = *aL, aux, ultim = NULL;

	while (p != NULL) {
		ultim = p;
		p = p->urm;
	}

	aux = AlocCelula(e);

	if (!aux)
		return 0;
	
	if (ultim) {
		ultim->urm = aux;
	} else {
		*aL = aux;
	}

	return 1;
}
```

## Citire Lista

```c
/* construieste lista cu elemente citite */

TLista CitireL(int *lg) {
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
```

## Eliminare element

```c

```