/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** h file
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <math.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Audio/Music.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/SoundBuffer.h>

#ifndef MY_RADAR_
    #define MY_RADAR_

    #include "plane.h"
    #include "tower.h"
    #include "simu.h"
    #include "corner.h"
    #include "window.h"
    #include "shape.h"
    #include "vector.h"
    #include "file.h"

typedef struct all_s {
    parameter_t parameters;
    simu_info_t simu_info;
    tower_t *array_towers;
    plane_t *array_planes;
} all_t;

void count_entity(all_t *ALL, char *pathfile);
void read_file(all_t *ALL, char *pathfile);
void parse_line(all_t *ALL, const char *line, int t_index, int p_index);
void mouse_pos(sfMouseButtonEvent event);

void display_planes(all_t *ALL);
void display_tower(all_t *ALL);
void display_tower_radius(all_t *ALL);
void display(all_t *ALL, sfClock *clock_move, float seconds);
void turn_sprite_show(all_t *ALL);
void turn_hitbox_show(all_t *ALL);
void show_option(all_t *ALL);

void move_planes(all_t *ALL);
void set_planes_move(all_t *ALL);
void set_planes_sprite(all_t *ALL);
void set_planes_hitbox(all_t *ALL);
void set_planes_circle(all_t *ALL);
void planes_collides(all_t *ALL);
void plane_detructible_update(all_t *ALL);
void collide(all_t *ALL);

void set_towers_sprite(all_t *ALL);
void set_towers_radius(all_t *ALL);

void assign_planes_to_zones(corner_t *corners, all_t *ALL);
void color_with_zone(all_t *ALL);

void set(all_t *ALL, corner_t *zones);
void init_clock(all_t *ALL, sfClock *clock);
int count_alive(all_t *ALL);

void init(all_t *all, char *pathfile);
void game(all_t *all);

#endif /* MY_RADAR_ */
