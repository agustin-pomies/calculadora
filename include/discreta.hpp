#ifndef _DISCRETA_H
#define _DISCRETA_H

typedef int num_t;

// BASES NUMERICAS
num_t base(num_t n, num_t base);

// DIVISIBILIDAD
num_t division_entera(num_t a, num_t b);

num_t modulo(num_t a, num_t b);

num_t gcd(num_t a, num_t b, bool extended);

num_t mcm(num_t a, num_t b);

num_t phi(num_t n);

void divisores_de(num_t n);

num_t cant_divisores(num_t n);

bool es_primo(num_t n);

bool es_anti_primo(num_t n);

// CRIPTOGRAFIA
num_t letra_a_numero(char c);

void encriptar_Cesar(string s, num_t e);

void encriptar_Vigenere(string s, string clave);

void encriptar_RSA(string s, num_t e);

void encriptar_ElGamal(string s, num_t e);

void encriptar_Eliptic_Curves(string s, num_t e);

// void encriptar_Cesar_polenta(string s, num_t e);

char numero_a_letra(num_t num);

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

#endif