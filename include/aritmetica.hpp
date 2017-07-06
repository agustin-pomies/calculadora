#ifndef _ARITMETICA_H
#define _ARITMETICA_H

type suma(type a; type b)
    return a+b; 

type resta(type a; type b)
    return a-b;

type producto(type a; type b)
    return a*b; 

// PRECONDICION: b != 0
type division_exacta(type a; type b)
    return a/b;

#endif