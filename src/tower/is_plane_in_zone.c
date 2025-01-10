/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main for my_hunters
*/
#include "my.h"
#include "my_radar.h"

int is_plane_in_zone(plane_t *plane, tower_t *tower)
{
    float distance = calc_dist(plane->position, tower->position);

    if (distance <= tower->radius) {
        plane->is_destructible = 0;
        return 1;
    } else {
        plane->is_destructible = 1;
        return 0;
    }
}

void plane_detructible_update(all_t *ALL)
{
    tower_t *current_tower;
    plane_t *current_plane;

    for (int i = 0; i < ALL->simu_info.count_towers; i++) {
        current_tower = &ALL->array_towers[i];
        for (int j = 0; j < ALL->simu_info.count_planes; j++) {
            current_plane = &ALL->array_planes[j];
            is_plane_in_zone(current_plane, current_tower);
        }
    }
}
