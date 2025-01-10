/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main for my_hunters
*/
#include "my.h"
#include "my_radar.h"

void set_towers_sprite(all_t *ALL)
{
    sfTexture *tower_texture = sfTexture_createFromFile("ressources/tower.png",
        NULL);

    for (int i = 0; i < ALL->simu_info.count_towers; i++) {
        TOWER_I.texture = tower_texture;
        TOWER_I.sprite = sfSprite_create();
        sfSprite_setTexture(TOWER_I.sprite, tower_texture, sfTrue);
        sfSprite_setScale(TOWER_I.sprite, (sfVector2f){0.15f, 0.15f});
        sfSprite_setOrigin(TOWER_I.sprite, (sfVector2f){256.0, 256.0});
        sfSprite_setPosition(TOWER_I.sprite, (sfVector2f){
            (float)TOWER_I.position.x,
            (float)TOWER_I.position.y});
    }
}

void set_towers_radius(all_t *ALL)
{
    for (int i = 0; i < ALL->simu_info.count_towers; i++) {
        TOWER_I.circle = create_circle((sfVector2f){
            (float)TOWER_I.position.x,
            (float)TOWER_I.position.y},
            (float)TOWER_I.radius);
    }
}
