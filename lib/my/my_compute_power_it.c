/*
** EPITECH PROJECT, 2024
** my_compute_power_it
** File description:
** Return power of a number
*/
#include "my.h"

int my_compute_power_it(int nb, int p)
{
    int res = 1;
    int count = 0;

    if (p == 0) {
        return 1;
    }
    if (p < 0) {
        return 0;
    }
    if (p == 1) {
        return nb;
    }
    while (count < p && res * nb < 2147483647) {
        count++;
        res *= nb;
    }
    return res;
}
