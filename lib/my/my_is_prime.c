/*
** EPITECH PROJECT, 2024
** my_is_prime
** File description:
** return 1 if prime number else 0
*/
#include "my.h"

int my_is_prime(int nb)
{
    if (nb <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= nb; i++) {
        if (nb % i == 0) {
            return 0;
        }
    }
    return 1;
}
