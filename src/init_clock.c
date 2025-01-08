/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main for my_hunters
*/
#include "my.h"
#include "my_radar.h"

void init_clock(all_t *ALL, sfClock *clock)
{
    ALL->simu_info.elapsed = sfClock_getElapsedTime(clock);
    ALL->simu_info.seconds = sfTime_asSeconds(ALL->simu_info.elapsed);
}
