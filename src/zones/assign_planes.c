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
            ALL->array_planes->zone = 0;
        }
        if (zone == 1) {
            ALL->array_planes->zone = 1;
        }
        if (zone == 2) {
            ALL->array_planes->zone = 2;
        }
        if (zone == 3) {
            ALL->array_planes->zone = 3;
        }
    }
}
