// #ifndef MODULAR_H
// #define MODULAR_H

extern int MOD;

int pnorm(int a);
int padd(int a, int b);
int psub(int a, int b);
int pmul(int a, int b);
int pdiv(int a, int b);
int mod_inverse(int a, int m);
int extended_gcd(int a, int b, int *x, int *y);

// #endif