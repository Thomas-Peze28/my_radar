/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main for my_hunters
*/
#include "my.h"
#include "my_radar.h"

int has_reach_dest(sfVector2i position, sfVector2i end_pos, sfVector2f traject)
{
    if ((traject.x > 0 && position.x >= end_pos.x) ||
        (traject.x < 0 && position.x <= end_pos.x) ||
        (traject.y > 0 && position.y >= end_pos.y) ||
        (traject.y < 0 && position.y <= end_pos.y)) {
        return 1;
    }
    return 0;
}

void reach_dest(plane_t *plane)
{
    plane->position = plane->end_pos;
    plane->is_alive = 0;
}

void close_to_dest(plane_t *plane, float distance_restante)
{
    if (distance_restante <= plane->speed * 3) {
        plane->position = plane->end_pos;
        plane->is_alive = 0;
    }
}

void move_planes(all_t *ALL)
{
    plane_t *plane;
    sfVector2f vecteur_directeur;
    float distance_restante;

    for (int i = 0; i < ALL->simu_info.count_planes; i++) {
        plane = &PLANE_I;
        if ((int)ALL->simu_info.seconds < plane->delay || !plane->is_alive)
            continue;
        vecteur_directeur = calculate_vector(plane->position, plane->end_pos);
        distance_restante = calc_dist(vecteur_directeur);
        close_to_dest(plane, distance_restante);
        sfSprite_move(plane->sprite, plane->trajectory);
        sfRectangleShape_move(plane->hitbox, plane->trajectory);
        sfCircleShape_move(plane->circle, plane->trajectory);
        plane->position.x += (int)plane->trajectory.x;
        plane->position.y += (int)plane->trajectory.y;
        if (has_reach_dest(plane->position, plane->end_pos, plane->trajectory))
            reach_dest(plane);
    }
}
