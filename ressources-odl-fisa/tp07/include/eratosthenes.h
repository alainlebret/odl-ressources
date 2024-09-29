#ifndef ERATOSTHENES_H
#define ERATOSTHENES_H

#include <stdio.h>
#include <math.h>

void initialize(int *primes, int n);

void display(int *primes, int n);

void select_multiples(int *primes, int n);

void sieve(int *primes, int n);

#endif /* ERATOSTHENES_H */