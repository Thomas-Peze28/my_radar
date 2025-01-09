/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main for my_hunters
*/
#include "my.h"
#include "my_radar.h"

void set_planes_move(all_t *ALL)
{
    plane_t *plane;
    sfVector2f vect_dir;
    float distance;

    for (int i = 0; i < ALL->simu_info.count_planes; i++) {
        plane = &PLANE_I;
        plane->is_alive = 1;
        vect_dir = calculate_vector(plane->position, plane->end_pos);
        distance = calc_dist(vect_dir);
        if (distance == 0) {
            plane->trajectory = (sfVector2f){0, 0};
            return;
        }
        plane->trajectory = calc_move_vector(plane->position,
            plane->end_pos, plane->speed);
    }
}

void set_planes_sprite(all_t *ALL)
{
    sfTexture *plane_texture = sfTexture_createFromFile("ressources/plane.png",
        NULL);
    float angle_deg;
    sfVector2f direction;

    for (int i = 0; i < ALL->simu_info.count_planes; i++) {
        PLANE_I.texture = plane_texture;
        PLANE_I.sprite = sfSprite_create();
        sfSprite_setTexture(PLANE_I.sprite, plane_texture, sfTrue);
        sfSprite_setOrigin(PLANE_I.sprite, (sfVector2f){160, 134.0});
        sfSprite_setScale(PLANE_I.sprite, (sfVector2f){0.1f, 0.1f});
        sfSprite_setPosition(PLANE_I.sprite, (sfVector2f){
            (float)PLANE_I.position.x,
            (float)PLANE_I.position.y});
        direction = calculate_vector(PLANE_I.position, PLANE_I.end_pos);
        angle_deg = atan2f(direction.y, direction.x) * (180.0f / 3.14);
        sfSprite_setRotation(PLANE_I.sprite, angle_deg);
    }
}

void set_planes_hitbox(all_t *ALL)
{
    float angle_deg;
    sfVector2f direction;

    for (int i = 0; i < ALL->simu_info.count_planes; i++) {
        PLANE_I.hitbox = create_rectangle((sfVector2f){
            (float)PLANE_I.position.x,
            (float)PLANE_I.position.y});
        direction = calculate_vector(PLANE_I.position, PLANE_I.end_pos);
        angle_deg = atan2f(direction.y, direction.x) * (180.0f / 3.14);
        sfRectangleShape_setRotation(PLANE_I.hitbox, angle_deg);
    }
}
