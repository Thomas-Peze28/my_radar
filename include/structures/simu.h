/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** h file
*/

#ifndef SIMU_
    #define SIMU_

    #include <SFML/Graphics.h>

typedef struct simu_info_s {
    int count_towers;
    int count_planes;
    int show_radius;
    sfTime elapsed;
    float seconds;
} simu_info_t;

#endif /* SIMU_ */
