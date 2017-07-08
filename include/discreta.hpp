#ifndef _DISCRETA_H
#define _DISCRETA_H

typedef int num_t;

// BASES NUMERICAS

// Devuelve el numero n (en base 10) expresado en la base indicada
// Precondicion: base > 1, n esta expresado en base 10
num_t base(num_t n, num_t base);

// DIVISIBILIDAD

// Devuelve el cociente de la division entera entre a y b
// Precondicion: a >= 0 y b > 0
num_t division_entera(num_t a, num_t b);

// Devuelve el modulo de la division entera entre a y b
// Precondicion: a >= 0 y  b > 0
num_t modulo(num_t a, num_t b);

// Devuelve el MCD entre a y b
// Precondicion: a > 0 y b > 0
num_t gcd(num_t a, num_t b);

// Devuelve el mcm entre a y b
// Precondicion: a > 0 y b > 0
num_t mcm(num_t a, num_t b);

// Devuelve la cantidad de numeros coprimos con n desde 1 hasta n
// Precondicion: n >= 0
num_t phi(num_t n);

// Devuelve en la salida estandar la lista ordenada de los divisiores de n
// Precondicion: n > 0
void divisores_de(num_t n);

// Devuelve la cantidad de divisores de n
// Precondicion: n > 0
num_t cant_divisores(num_t n);

// Devuelve true si n es primo, false en otro caso
// Precondicion: n > 0
bool es_primo(num_t n);

// Devuelve true si el numero ingresado tiene la mayor cantidad de divisores hasta n
// Precondicion: n > 0
bool es_anti_primo(num_t n);

// CRIPTOGRAFIA

// Asocia un caracter a un numero por su posicion alfabetica
// Precondicion: c pertenece al conjunto {a, b, ..., z, _}
num_t letra_a_numero(char c);

// Devuelve una string el mensaje de s cifrado por metodo Cesar con la clave e
// Precondicion: e >= 0
// AYUDA: observar que el resultado es el mismo si e es congruente con e', siendo 0 <= e' <= mod
string encriptar_Cesar(string s, num_t e);

// Devuelve una string con el mensaje de s cifrado por metodo Vigenere con la string clave
string encriptar_Vigenere(string s, string clave);

// Devuelve una string con el mensaje de s cifrado por metodo RSA FIXME
// FIXME:
string encriptar_RSA(string s, num_t e);

// Devuelve una string con el mensaje de s cifrado por metodo ElGamal FIXME
// FIXME:
string encriptar_ElGamal(string s, num_t e);

// Devuelve una string con el mensaje de s cifrado por Curvas elpiticas FIXME
// FIXME:
string encriptar_Eliptic_Curves(string s, num_t e);

// Devuelve una string con el mensaje de s cifrado por afin
// Precondicion: gcd(a, mod) = 1, a != 0
// AYUDA: observar que el resultado es el mismo si 
// $ b es congruente con b', siendo 0 <= b' <= mod
// $ |a| = a', es decir a' >= 1 
string encriptar_afin(string s, num_t a, num_t b);

// Asocia un numero a un caracter por su posicion alfabetica
// Precondicion: num esta en [0, 27]
char numero_a_letra(num_t num);

// Devuelve una string el mensaje de s descifrado por metodo Cesar con la clave d
// Precondicion: d >= 0
string desencriptar_Cesar(string s, num_t d);

// Devuelve una string con el mensaje de s descifrado por metodo Vigenere con la string clave
string desencriptar_Vigenere(string s, string clave);

// Devuelve una string con el mensaje de s descifrado por metodo RSA FIXME
// FIXME
string desencriptar_RSA(string s, num_t d);

// Devuelve una string con el mensaje de s descifrado por metodo ElGamal FIXME
// FIXME
string desencriptar_ElGamal(string s, num_t d);

// Devuelve una string con el mensaje de s descifrado por Curvas elpiticas FIXME
// FIXME
string desencriptar_Eliptic_Curves(string s, num_t d);

// Devuelve una string con el mensaje de s descifrado por afin
// Precondicion: gcd(a, mod) = 1, a != 0
// AYUDA: observar que el resultado es el mismo si 
// $ b es congruente con b', siendo 0 <= b' <= mod
// $ |a| = a', es decir a' >= 1 
string encriptar_Cesar_polenta(string s, num_t a, num_t b);

// Calcula la clave de cifrado por el metodo de Diffie-Hellman
// Precondicion: 1 < g < p, es_primo(p), g es raiz primitiva
// AYUDA:
// n y m se pueden llevar a sus congruentes mod p
// FIXME: como saber si g es raiz primitiva
num_t Diffie_Hellman(num_t p, num_t g, num_t n, num_t m);

// COMBINATORIA

// rep = true
// Devuelve los arreglos con repeticion de n en p
// Precondicion: n >= 0, p >= 0, p <= n
// AYUDA: 
// formula A(n, p) = p^n

// rep = false
// Devuelve los arreglos sin repeticion de n en p
// Precondicion: n >= 0, p >= 0, p <= n
// AYUDA: 
// A(n, 0) = 1
num_t arreglos(num_t n, num_t p, bool rep);

// rep = true
// Devuelve las combinaciones con repeticion de n en p
// Precondicion: n >= 0, k >= 0, k <= n
// AYUDA: formula C(n+k-1, k)

// rep = false
// Devuelve las combinaciones sin repeticion de n en p
// Precondicion: n >= 0, p >= 0, k <= n
// AYUDA: 
// C(n,0) = 1, 
// C(n, k) = C(n, n-k), 
num_t comb(num_t n, num_t p, bool rep);

// Devuelve el factorial de un numero
// Precondicion: n >= 0
num_t factorial(num_t n);

// Devuelve el numero de Stirling de primera especie de n en p
// Precondicion: n >= 0, p >= 0, p <= n
num_t Stirling_1(num_t n, num_t p);

// Devuelve el numero de Stirling de segunda especie de n en p
// Precondicion: n >= 0, p >= 0, p <= n
num_t Stirling_2(num_t n, num_t p);

// CONGRUENCIAS

// FIXME
void inv_modular(num_t a, num_t mod);

#endif