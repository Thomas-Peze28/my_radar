/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main for my_hunters
*/
#include "my.h"
#include "my_radar.h"

void destroy_zones(corner_t *zones)
{
    for (int i = 0; i < 4; i++) {
        free(zones[i].array_planes);
    }
}
