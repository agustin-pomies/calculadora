#include "../include/discreta.hpp"
#include <stdlib.h>

num_t division_entera(num_t a, num_t b) {return (num_t)(a/b);} 

num_t modulo(num_t a, num_t b) {return a%b;}

// Orden: log(n)
num_t gcd(num_t a, num_t b, bool extended) {
    // ALGORITMO DE EUCLIDES TRADICIONAL
    num_t r = modulo(a,b);
    while(r != 0) {
        a = b;
        b = r;
        r = modulo(a, b);
    };
    return b;

    // ALGORITMO DE EUCLIDES EXTENDIDO
    num_t aux = 0;
    num_t matrix [2][2];
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++) {
            if(i == j)
                matrix [i][j] = 1;
            else
                matrix [i][j] = 0;
        };
    num_t q = division_entera(a, b);
    num_t r = modulo(a,b);
    while(r != 0) {
        for(int i = 0; i < 2; i++) {
            aux = matrix[0][i];
            matrix[0][i] = matrix[1][i];
            matrix[1][i] = aux - q*matrix[1][i];
        };
        a = b;
        b = r;
        q = division_entera(a,b);
        r = modulo(a,b);
    };
    // Los coeficientes de Bezout son las entradas [1][0] y [1][1]
    // El valor de b es el gcd
    return b;
}

num_t mcm(num_t a, num_t b) {return a*b/gcd(a, b, false);}

num_t phi(num_t n);

void divisores_de(num_t n);

num_t cant_divisores(num_t n);

bool es_primo(num_t n);

bool es_anti_primo(num_t n);

// CRIPTOGRAFIA
void encriptar_Cesar(string s, num_t e);

void encriptar_Vigenere(string s, string clave);

void encriptar_RSA(string s, num_t e);

void encriptar_ElGamal(string s, num_t e);

void encriptar_Eliptic_Curves(string s, num_t e);

// void encriptar_Cesar_polenta(string s, num_t e);

void desencriptar_Cesar(string s, num_t d);

void desencriptar_Vigenere(string s, string clave);

void desencriptar_RSA(string s, num_t d);

void desencriptar_ElGamal(string s, num_t d);

void desencriptar_Eliptic_Curves(string s, num_t d);

// void encriptar_Cesar_polenta(string s, num_t e);

num_t Diffie_Hellman(num_t g, num_t n, num_t m);

// CONTABILIDAD
num_t arreglos(num_t n, num_t p);

num_t comb(num_t n, num_t p);

num_t factorial(num_t n);

num_t Stirling_1();

num_t Stirling_2();

// CONGRUENCIAS
void inv_modular(num_t a, num_t mod);

// GRAFOS
