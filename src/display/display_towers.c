/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main for my_hunters
*/
#include "my.h"
#include "my_radar.h"

void display_tower(all_t *ALL)
{
    for (int i = 0; i < ALL->simu_info.count_towers; i++) {
        sfRenderWindow_drawSprite(WIN.window,
            TOWER_I.sprite, NULL);
    }
}

void display_tower_radius(all_t *ALL)
{
    plane_t *plane;

    if (ALL->simu_info.show_radius == 1)
        return;
    for (int i = 0; i < ALL->simu_info.count_towers; i++) {
        sfRenderWindow_drawCircleShape(WIN.window, TOWER_I.circle, NULL);
    }
    for (int i = 0; i < ALL->simu_info.count_planes; i++) {
        plane = &PLANE_I;
        if (!plane->is_alive)
            continue;
        sfRenderWindow_drawRectangleShape(WIN.window, PLANE_I.hitbox, NULL);
        sfRenderWindow_drawCircleShape(WIN.window, PLANE_I.circle, NULL);
    }
}
