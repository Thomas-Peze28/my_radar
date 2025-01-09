/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main for my_hunters
*/
#include "my.h"
#include "my_radar.h"

void set(all_t *ALL)
{
    set_towers_sprite(ALL);
    set_towers_radius(ALL);
    set_planes_sprite(ALL);
    set_planes_hitbox(ALL);
    set_planes_move(ALL);
}
