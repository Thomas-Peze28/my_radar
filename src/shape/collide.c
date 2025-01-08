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
