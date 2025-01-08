/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main for my_hunters
*/
#include "my.h"
#include "plane.h"
#include "my_radar.h"

void init_info_simu(all_t *ALL, char *pathfile)
{
    count_entity(ALL, pathfile);
    ALL->simu_info.show_radius = 0;
}

void init_towers(all_t *ALL)
{
    ALL->array_towers = malloc(sizeof(tower_t) * ALL->simu_info.count_towers);
}

void init_planes(all_t *ALL)
{
    ALL->array_planes = malloc(sizeof(plane_t) * ALL->simu_info.count_planes);
}

void init_window(all_t *ALL)
{
    WIN.video_mode.height = 1080;
    WIN.video_mode.width = 1920;
    WIN.video_mode.bitsPerPixel = 32;
    WIN.window = sfRenderWindow_create(WIN.video_mode, "MY RADAR"
    , sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(WIN.window, 60);
    WIN.bg_texture = sfTexture_createFromFile("ressources/map.jpg", NULL);
    WIN.bg_sprite = sfSprite_create();
    sfSprite_setTexture(WIN.bg_sprite, WIN.bg_texture, sfTrue);
}

void init(all_t *ALL, char *pathfile)
{
    init_window(ALL);
    init_info_simu(ALL, pathfile);
    init_towers(ALL);
    init_planes(ALL);
}
