/*-- tlg.h --- LISTA SIMPLU INLANTUITA GENERICA ---*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>

#ifndef _LISTA_GENERICA_
#define _LISTA_GENERICA_

#define STRING_LENGTH 16

typedef struct celulag
{
  void* info;           /* adresa informatie */
  struct celulag *urm;   /* adresa urmatoarei celule */
} TCelulaG, *TLG; 	/* tipurile Celula, Lista generice */

typedef struct {
    char *author;
    char *title;
    int publishedDate;
} Book;


/* functii lista generica */
TLG Aloc_CelulaG(void* x);

int Ins_IncLG(TLG*, void*);  /*- inserare la inceput reusita sau nu (1/0) -*/

void DistrugeLG(TLG* aL, void (*fe)(void*)); /* distruge lista */

/* afiseaza elementele din lista, folosind o functie de Afișare element specific*/
void AfisareLG(TLG, void (*afi_el)(void*));

// By me

// ex 1
int checkListItems(TLG, int (*)(void *));
int isEven(void *);

// ex 2
void afi_book(void *);
void free_book(void *);
void readBook(Book *);

void insertCell(TLG *, TLG);

void ex2B(TLG);
void ex2C(TLG *);

#endif
