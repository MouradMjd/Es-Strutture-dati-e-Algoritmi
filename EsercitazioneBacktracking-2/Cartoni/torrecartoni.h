#if !defined CARTONI_H
#define CARTONI_H

#include<stdlib.h>
typedef struct {
    unsigned p; // Peso
    unsigned a; // Altezza
    unsigned l; // Limite
} Cartone;

extern void TorreCartoni(const Cartone* c, size_t n);

#endif // !defined CARTONI_H


