/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main for my_hunters
*/
#include "my.h"
#include "my_radar.h"

int is_intersecting_circles(sfCircleShape *c1, sfCircleShape *c2)
{
    sfVector2f pos_c1 = sfCircleShape_getPosition(c1);
    sfVector2f pos_c2 = sfCircleShape_getPosition(c2);
    float rad_c1 = sfCircleShape_getRadius(c1);
    float rad_c2 = sfCircleShape_getRadius(c2);
    float center_c1_x = pos_c1.x + rad_c1;
    float center_c1_y = pos_c1.y + rad_c1;
    float center_c2_x = pos_c2.x + rad_c2;
    float center_c2_y = pos_c2.y + rad_c2;
    float i = ((center_c1_x - center_c2_x) * (center_c1_x - center_c2_x)) +
        ((center_c1_y - center_c2_y) * (center_c1_y - center_c2_y));
    float j = ((rad_c1 + rad_c2) * (rad_c1 + rad_c2));

    if (i <= j) {
        sfCircleShape_setFillColor(c1, sfWhite);
        sfCircleShape_setFillColor(c2, sfWhite);
        return 1;
    } else {
        return 0;
    }
}

int are_intervals_overlap(float start1, float end1, float start2, float end2)
{
    return start1 <= end2 && start2 <= end1;
}

int is_intersecting_square(sfRectangleShape *c1, sfRectangleShape *c2)
{
    sfVector2f pos_c1 = sfRectangleShape_getPosition(c1);
    sfVector2f pos_c2 = sfRectangleShape_getPosition(c2);
    float c1_left = pos_c1.x - 10;
    float c1_right = pos_c1.x + 10;
    float c1_top = pos_c1.y - 10;
    float c1_bottom = pos_c1.y + 10;
    float c2_left = pos_c2.x - 10;
    float c2_right = pos_c2.x + 10;
    float c2_top = pos_c2.y - 10;
    float c2_bottom = pos_c2.y + 10;

    if (are_intervals_overlap(c1_left, c1_right, c2_left, c2_right) &&
        are_intervals_overlap(c1_top, c1_bottom, c2_top, c2_bottom)) {
        return 1;
    }
    return 0;
}

void check_collide(all_t *ALL, int i, int j)
{
    if (ALL->array_planes[j].hitbox != NULL) {
        if (ALL->array_planes[i].is_destructible == 0 ||
            ALL->array_planes[i + 1].is_destructible == 0) {
            return;
        }
        if (ALL->array_planes[i].is_alive == 0 ||
            ALL->array_planes[j].is_alive == 0) {
            return;
        }
        if (PLANE_I.zone != ALL->array_planes[j].zone) {
            return;
        }
        if (is_intersecting_square(PLANE_I.hitbox,
            ALL->array_planes[j].hitbox) == 1) {
            ALL->array_planes[i].is_alive = 0;
            ALL->array_planes[j].is_alive = 0;
        }
    }
}

void collide(all_t *ALL)
{
    int i = 0;
    int j = i + 1;

    plane_detructible_update(ALL);
    for (i = 0; i < ALL->simu_info.count_planes; i++) {
        for (j = i + 1; j < ALL->simu_info.count_planes; j++) {
            check_collide(ALL, i, j);
        }
    }
}
