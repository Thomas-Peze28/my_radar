/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main for my_hunters
*/
#include "my.h"
#include "my_radar.h"

sfCircleShape *create_circle(sfVector2f position, float radius)
{
    sfCircleShape *circle;

    circle = sfCircleShape_create();
    sfCircleShape_setOutlineColor(circle, sfWhite);
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setOutlineThickness(circle, 1.0);
    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setOrigin(circle, (sfVector2f){radius, radius});
    sfCircleShape_setPosition(circle, position);
    return circle;
}

sfRectangleShape *create_rectangle(sfVector2f position)
{
    sfRectangleShape *rectangle;

    rectangle = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(rectangle, sfWhite);
    sfRectangleShape_setFillColor(rectangle, sfTransparent);
    sfRectangleShape_setOutlineThickness(rectangle, 1.0);
    sfRectangleShape_setSize(rectangle, (sfVector2f){20, 20});
    sfRectangleShape_setOrigin(rectangle, (sfVector2f){10, 10});
    sfRectangleShape_setPosition(rectangle, position);
    return rectangle;
}
