# 14.03.2022

## Ex. 1
```c
TLista Copie(TLista L, int a, b, int *count);
```

- functia intoarce o lista cu elementele din L cuprinse intre a si b

ex:
```c
L = 3 4 5 6 7
a = 4
b = 7

R = 5 6
2
```

```c
TLista Copie(TLista L, int a, int b, int *count){
    while (L) {
        if (L->info <= a)
            L = L->urm;
        else if (L->info < b) {
            aux = AlocaCelula(L->info);
            if (R == NULL)
                R = aux;
            else
                u->urm = aux;

            u = aux;

            L = L->urm;
        } else
            break;
    }
}
```

## Ex. 2

Fara `AlocaCelula()` sau `DistrugeLista()`.

```c
TLista Muta(TLista *L, int k);

```

- daca se imparte la `k`, muta elementul in lista `R`

```c
L = 1 2 3 4 5 6
k = 2

L = 1 3 5
R = 2 4 6i
3
```

```c
//aux->urm = L->urm;

while (L) {
    if ( L->info % k == 0 ) {
        adaugati L->info la R;
        aux->urm = L->urm;
    } else {
        aux = L;
        L = L->urm;
    }
}
```
