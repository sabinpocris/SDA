# Lab - 21.03.2022

## Ex 1.

```c
// kinda like a map
int checkListItems(TLG list, int (*test)(void *)) {
    int count = 0;

    while (list != NULL) {
        if ((*test)(list->info))
            count++;

        list = list->urm;
    }

    return count;
}

// checks if it is an even integer
int isEven(void *number) {
    if (*(int *)number  % 2 == 0)
        return 1;

    return 0;
}
```

## Ex 2.

```c
typedef struct {
    char *author;
    char *title;
    int publishedDate;
} Book;
```

```c
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
```

```c
int isEvenYearPublished(void *info) {
    if (((Book *)info )->publishedDate % 2)
        return 0;

    return 1;
}

void ex2B(TLG list) {
    int option = 0;
    printf("Do you want to apply isEven() on book.year?(0/1): ");
    
    scanf("%d", &option);

    if (option) {
        printf("%d\n", checkListItems(list, isEvenYearPublished));
    }
    
    return;
}
```


```c
int getYearPubBook(void *temp) {
    return ((Book *) temp)->publishedDate;
}

void ex2C(TLG *list) {
    int a = 0, b = 0;
    TLG temp;

    printf("The period you want to remove:\na = ");
    scanf("%d", &a);

    printf("b = ");
    scanf("%d", &b);

    // removing the first note
    while (getYearPubBook((*list)->info) >= a 
            && getYearPubBook((*list)->info) <= b
            && (*list) != NULL) {
        TLG temp = (*list);
        
        (*list) = (*list)->urm;

        DistrugeLG(&temp, free_book);
    }

	// removing from the middle
    for (temp = (*list); 
            temp != NULL; temp = temp->urm) {
        if (temp->urm->urm == NULL)
            break;


        if (getYearPubBook(temp->urm->info) >= a &&
                getYearPubBook(temp->urm->info) <= b) {
            TLG keep = temp->urm;
            keep->urm = NULL;

            temp->urm = temp->urm->urm;
            
            DistrugeLG(&keep, free_book);
        }
    }
    
	// removing the last
    if (getYearPubBook(temp->urm->info) >= a &&
                getYearPubBook(temp->urm->info) <= b) {
            DistrugeLG(&(temp->urm), free_book);
            temp->urm = NULL;
    }
    
    return;
}
```
