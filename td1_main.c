#include <stdio.h>
#include <stdlib.h>

/**
 * nb complexe
 */
typedef struct{
    int x; /**< réel*/
    int y; /**< imaginaire*/
}nbcomplexe;

/**
 * nb complexe + fcts
 */
typedef struct{
    nbcomplexe nbComplexe; /**< nb complexe*/
    void (*fctPrint)(nbcomplexe *internal_nb); /**< fct print*/
}complexe;

void printCplx(const complexe *nb){
    printf("Nb complexe : r=%d, i=%d\n", nb->nbComplexe.x, nb->nbComplexe.y);
}

void addCplx(complexe *dest, const complexe *a, const complexe *b){
    dest->nbComplexe.x=a->nbComplexe.x + b->nbComplexe.x;
    dest->nbComplexe.y=a->nbComplexe.y + b->nbComplexe.y;
}

int td1_main(){
    complexe a;
    complexe *b;
    complexe *c;

    a.nbComplexe.x=1;
    a.nbComplexe.y=2;
    a.fctPrint=(void *)printCplx;

    b=(complexe*)malloc(sizeof(complexe));
    b->nbComplexe.x=3;
    b->nbComplexe.y=4;
    b->fctPrint=(void*)printCplx;

    (*a.fctPrint)(&a.nbComplexe);
    (*b->fctPrint)(&b->nbComplexe);

    c=(complexe*)malloc(sizeof(complexe));
    c->fctPrint=(void*)printCplx;
    addCplx(c, &a, b);
    (*c->fctPrint)(&c->nbComplexe);

    free(b);
    free(c);
    return 0;
}

