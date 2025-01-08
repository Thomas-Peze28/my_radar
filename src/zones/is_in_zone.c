/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main for my_hunters
*/
#include "my.h"
#include "my_radar.h"

int is_in_zone(corner_t corner, sfVector2f position)
{
    return (position.x >= corner.area.left &&
            position.x < corner.area.left + corner.area.width &&
            position.y >= corner.area.top &&
            position.y < corner.area.top + corner.area.height);
}
