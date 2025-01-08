/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** h file
*/

#ifndef PLANE_
    #define PLANE_

    #define PLANE_I ALL->array_planes[i]

    #include <SFML/Graphics.h>

typedef struct plane_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f scale;
    sfIntRect rect;
    sfVector2i position;
    sfVector2f trajectory;
    sfVector2i end_pos;
    sfRectangleShape *hitbox;
    sfCircleShape *circle;
    int is_destructible;
    int is_alive;
    int speed;
    int delay;
    int zone;
} plane_t;

#endif /* PLANE_ */
