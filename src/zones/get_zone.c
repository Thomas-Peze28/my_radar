/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main for my_hunters
*/
#include "my.h"
#include "my_radar.h"

int get_zone(corner_t *corners, sfVector2f position)
{
    for (int i = 0; i < 4; i++) {
        if (is_in_zone(corners[i], position)) {
            return i;
        }
    }
    return 84;
}
