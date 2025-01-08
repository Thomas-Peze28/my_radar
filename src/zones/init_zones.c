/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main for my_hunters
*/
#include "my.h"
#include "my_radar.h"

void initialize_zones(corner_t *zones)
{
    zones[0].area = (sfIntRect){0, 0, 960, 540};
    zones[1].area = (sfIntRect){960, 0, 960, 540};
    zones[2].area = (sfIntRect){0, 540, 960, 540};
    zones[3].area = (sfIntRect){960, 540, 960, 540};
}
