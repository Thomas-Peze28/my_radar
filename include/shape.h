/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** h file
*/

#ifndef SHAPE_
    #define SHAPE_

    #include <SFML/Graphics.h>

sfCircleShape *create_circle(sfVector2f position, float radius);
sfRectangleShape *create_rectangle(sfVector2f position);
int is_intersecting_circles(sfCircleShape *c1, sfCircleShape *c2);
int is_intersecting_square(sfRectangleShape *c1, sfRectangleShape *c2);

#endif /* SHAPE_ */
