# 03.03.2022 - Liste

## Alocare Celula

```c
TLista AlocCelula(int x) {
	TLista aux;
	aux = malloc(sizeof(TCelula));

	if (!aux)
		return NULL;

	aux->info = x;
	aux->urm = NULL;

	return aux;
}
```

## Inserare dupa o anumite celula

```c
// intoarce adresa celulei inserate sau NULL ?? nu cred
int InserareDupa(TLista, int e, int ref) {
	TLista aux, p;

	for (p = NULL; L != NULL; L = L->urm) {
		if (L->info == ref) {
			p = L;
			break;
		}
	}

	if (!p)
		return 0;
	
	aux = AlocCelula(e);

	if (!aux)
		return 0;

	aux->urm = p->urm;
	p->urm = aux;

	return 1;
}
```

## Inserare la inceputul listei

```c
int InsInc(TLista *aL, int e) {
	TLista aux = malloc(sizeof(TCelula));

	if (!aux)
		return 0;

	aux->info = e;
	aux->urm = *aL;
	*aL = aux;

	return 1;
}
```

## Inserare in fata unei celule

```c
int InserareInainte(TLista *aL, int e, int ref) {
	TLista aux, ant, p, L;

	for (ant = NULL, p = NULL, L = *aL;
		L != NULL; ant = L; L = L->urm) {
			if (L->info == ref) {
				p = L;
				break;
			}
	}

	if (!p)
		return 0;
	
	aux = AlocCelula(e);

	if (!aux)
		return 0;
	
	if (ant == NULL) {
		aux->urm = p;
		*aL = aux;
	} else {
		aux->urm = p;
		ant->urm = aux;
	}

	return 1;
}
```

## Inserare la sfarsitul listei

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