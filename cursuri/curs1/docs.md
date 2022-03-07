# 1.03.2022

- Lista
- Coada
- HashTable(Dictionar)
- Stiva
- Arbori
- Arbori binari
	- expresii aritmetice
	- arbori binari de cautare
- Grafuri

## Liste simplu inlantuite

### Definite

```c
typedef struct celula
{
	int info;
	struct celula *urm;
} TCelula, *TLista, **ALista; 

TLista L;

// checking the pointer if it is valid
if (L != NULL) {
	// valoarea primului element
	L->info;

	// adresa urmatoarei celule
	L->urm;

	// valoarea urmatorului element
	L->urm->info;

	// avans la urmatoare celula
	L = L->urm;
}
```

### Afisare lista

```c
void afisareLista(TLista L) {
	TLista p = L;

	for ( ; p != NULL; p = p->urm) {
		printf("%d ", p->info);
	}
}
```