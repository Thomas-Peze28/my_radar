/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** h file
*/

#ifndef TOWER_
    #define TOWER_

    #define TOWER_I ALL->array_towers[i]

    #include <SFML/Graphics.h>

typedef struct tower_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f scale;
    sfVector2f position;
    int radius;
    sfCircleShape *circle;
} tower_t;

int is_plane_in_zone(plane_t *plane, tower_t *tower);

#endif /* TOWER_ */
