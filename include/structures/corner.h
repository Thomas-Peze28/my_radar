/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** h file
*/

#ifndef CORNER_
    #define CORNER_

    #include <SFML/Graphics.h>
    #include "plane.h"

typedef struct corner_s {
    sfIntRect area;
    unsigned int nb_planes;
    plane_t *array_planes;
} corner_t;

void destroy_zones(corner_t *zones);
void initialize_zones(corner_t *zones);
int get_zone(corner_t *corners, sfVector2f position);
int is_in_zone(corner_t corner, sfVector2f position);

#endif /* CORNER_ */
