/*--- functiiLG.c -- operatii de baza pentru lista simplu inlantuita generica---*/
#include "tlg.h"
#include <stdlib.h>

TLG Aloc_CelulaG(void* x)
{
	TLG aux;
  	aux = (TLG)malloc(sizeof(TCelulaG));
   	if(!aux) return NULL;
   	
	aux->info = x;
	aux->urm = NULL;
	return aux;
}

int Ins_IncLG(TLG* aL, void* ae)
{
	TLG aux = Aloc_CelulaG(ae);
	if(!aux)
	    return 0;

	aux->urm = *aL;
	*aL = aux;

	return 1;
}

void DistrugeLG(TLG* aL, void (*free_elem)(void*)) /* distruge lista */
{
	TLG aux;
	while(*aL != NULL)
    	{
        		aux = *aL;     /* adresa celulei eliminate */
        		if (!aux)
            		return;

        		free_elem(aux->info);  /* elib.spatiul ocupat de element*/
        		*aL = aux->urm;    /* deconecteaza celula din lista */
        		free(aux);   /* elibereaza spatiul ocupat de celula */
    	}
}


void AfisareLG(TLG L, void (*afiEL)(void*)) {
    if(!L) {
       printf("Lista vida\n");
       return;
    }

	printf("Lista: [");
	for(; L; L = L->urm) 
		afiEL(L->info);
    
	printf("]\n");
}

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

void afi_book(void *item) {
    Book *tempBook = (Book *) item;

    printf("\n===\n");
    printf("Title: %s\n", tempBook->title);
    printf("Author: %s\n", tempBook->author);
    printf("Published Date: %d\n", tempBook->publishedDate);
    printf("===\n");
}

void free_book(void *item) {
    Book *tempBook = (Book *) item;

    free(tempBook->author);
    free(tempBook->title);

    free(item);
}

void readBook(Book *elem) {
    // read in the data
    elem->author = malloc(sizeof(char) * STRING_LENGTH);
    elem->title = malloc(sizeof(char) * STRING_LENGTH);

    printf("Author: ");
    scanf("%s", elem->author);

    printf("Title: ");
    scanf("%s", elem->title);

    printf("Published date: ");
    scanf("%d", &(elem->publishedDate));    
}

// b1 >= b2 returns 1
// b1 < b2 return 0
int compareBooksByYear(Book *b1, Book *b2) {
    if (b1->publishedDate >= b2->publishedDate)
        return 1;

    return 0;
}

// insereaza o celula in mod crescator
void insertCell(TLG *tempList, TLG cell) {
    TLG list = *tempList;
    //size 0
    if (*tempList == NULL) {
        *tempList = cell;

        return;
    }

    // size 1
    if ((*tempList)->urm == NULL) {
        if (compareBooksByYear((Book *) (*tempList)->info, (Book *) cell->info)) {
            TLG temp = (*tempList);
            *tempList = cell;
            (*tempList)->urm = temp;
        } else {
            (*tempList)->urm = cell;
        }

        return;
    }
    
    // insert at the start
    if (compareBooksByYear((Book *) (*tempList)->info, (Book *) cell->info)) {
        TLG temp = (*tempList);
        *tempList = cell;
        (*tempList)->urm = temp;

        return;
    }

    // size 2+
    for (; list->urm != NULL; list = list->urm) {
        if (compareBooksByYear((Book *)list->urm->info, (Book *)cell->info)) {
            TLG temp = list->urm;

            list->urm = cell;
            list->urm->urm = temp;

            return;
        }
    }

    // insert at the end
    list->urm = cell;
    return;
}

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
    
    if (getYearPubBook(temp->urm->info) >= a &&
                getYearPubBook(temp->urm->info) <= b) {
            DistrugeLG(&(temp->urm), free_book);
            temp->urm = NULL;
    }
    
    return;
}
