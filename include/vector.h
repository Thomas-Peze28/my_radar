/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** h file
*/

#ifndef VECTOR_
    #define VECTOR_

    #include <SFML/Graphics.h>

sfVector2f calculate_vector(sfVector2i start, sfVector2i end);
sfVector2f normalize_vector(sfVector2f vector);
sfVector2f apply_speed_to_vector(sfVector2f vector, float speed);
sfVector2f calc_move_vector(sfVector2i start, sfVector2i end, float speed);
float calc_dist(sfVector2f vector);

#endif /* VECTOR_ */
