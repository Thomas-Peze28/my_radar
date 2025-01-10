/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main for my_hunters
*/
#include "my.h"
#include "my_radar.h"

void assign_planes_to_zones(corner_t *corners, all_t *ALL)
{
    int zone;

    for (int i = 0; i < ALL->simu_info.count_planes; i++){
        zone = get_zone(corners, (sfVector2f){
            PLANE_I.position.x,
            PLANE_I.position.y});
        if (zone == 0) {
            ALL->array_planes[i].zone = 0;
        }
        if (zone == 1) {
            ALL->array_planes[i].zone = 1;
        }
        if (zone == 2) {
            ALL->array_planes[i].zone = 2;
        }
        if (zone == 3) {
            ALL->array_planes[i].zone = 3;
        }
    }
    color_with_zone(ALL);
}

void color_with_zone(all_t *ALL)
{
    for (int i = 0; i < ALL->simu_info.count_planes; i++) {
        if (PLANE_I.zone == 0)
            sfRectangleShape_setOutlineColor(PLANE_I.hitbox, sfGreen);
        if (PLANE_I.zone == 1)
            sfRectangleShape_setOutlineColor(PLANE_I.hitbox, sfBlue);
        if (PLANE_I.zone == 2)
            sfRectangleShape_setOutlineColor(PLANE_I.hitbox, sfRed);
        if (PLANE_I.zone == 3)
            sfRectangleShape_setOutlineColor(PLANE_I.hitbox, sfYellow);
    }
}
