/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main for my_hunters
*/
#include "my.h"
#include "my_radar.h"

void display_planes(all_t *ALL)
{
    plane_t *plane;

    for (int i = 0; i < ALL->simu_info.count_planes; i++) {
        plane = &PLANE_I;
        if (plane->is_alive == 0 || ALL->simu_info.seconds < plane->delay)
            continue;
        sfRenderWindow_drawSprite(WIN.window, PLANE_I.sprite, NULL);
    }
}
