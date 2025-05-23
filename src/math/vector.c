/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main for my_hunters
*/
#include "my.h"
#include "my_radar.h"

sfVector2f calculate_vector(sfVector2f start, sfVector2f end)
{
    sfVector2f vector;

    vector.x = (float)(end.x - start.x);
    vector.y = (float)(end.y - start.y);
    return vector;
}

sfVector2f normalize_vector(sfVector2f vector)
{
    float length = sqrtf(vector.x * vector.x + vector.y * vector.y);

    if (length != 0) {
        vector.x /= length;
        vector.y /= length;
    }
    return vector;
}

sfVector2f apply_speed_to_vector(sfVector2f vector, float speed)
{
    vector.x *= speed;
    vector.y *= speed;
    return vector;
}

sfVector2f calc_move_vector(sfVector2f start, sfVector2f end, float speed)
{
    sfVector2f vector = calculate_vector(start, end);

    vector = normalize_vector(vector);
    vector = apply_speed_to_vector(vector, speed);
    return vector;
}

float calc_dist(sfVector2f vector1, sfVector2f vector2)
{
    float dx = vector2.x - vector1.x;
    float dy = vector2.y - vector1.y;

    return sqrtf(dx * dx + dy * dy);
}
