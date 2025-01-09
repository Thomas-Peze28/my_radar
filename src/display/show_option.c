/*
** EPITECH PROJECT, 2024
** window.c
** File description:
** window for my_hunter
*/
#include "my.h"
#include "my_radar.h"

void turn_sprite_show(all_t *ALL)
{
    if (ALL->simu_info.show_sprites == 1) {
        ALL->simu_info.show_sprites = 0;
        return;
    }
    if (ALL->simu_info.show_sprites == 0) {
        ALL->simu_info.show_sprites = 1;
        return;
    }
}

void turn_hitbox_show(all_t *ALL)
{
    if (ALL->simu_info.show_radius == 1) {
        ALL->simu_info.show_radius = 0;
        return;
    }
    if (ALL->simu_info.show_radius == 0) {
        ALL->simu_info.show_radius = 1;
        return;
    }
}

void show_option(all_t *ALL)
{
    if (WIN.event.key.code == sfKeyS) {
        turn_sprite_show(ALL);
    }
    if (WIN.event.key.code == sfKeyL) {
        turn_hitbox_show(ALL);
    }
}
