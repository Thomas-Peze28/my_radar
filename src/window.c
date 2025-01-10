/*
** EPITECH PROJECT, 2024
** window.c
** File description:
** window for my_hunter
*/
#include "my.h"
#include "my_radar.h"

int count_alive(all_t *ALL)
{
    int count = 0;

    for (int i = 0; i < ALL->simu_info.count_planes; i++) {
        if (PLANE_I.is_alive)
            count++;
    }
    return count;
}

void display(all_t *ALL, sfClock *clock_move, float seconds)
{
    sfRenderWindow_clear(WIN.window, sfBlack);
    sfRenderWindow_drawSprite(WIN.window, WIN.bg_sprite, NULL);
    display_tower_radius(ALL);
    if (ALL->simu_info.show_sprites == 0) {
        display_tower(ALL);
        display_planes(ALL);
    }
    if (seconds > 0.1f) {
        move_planes(ALL);
        sfClock_restart(clock_move);
    }
    sfRenderWindow_display(WIN.window);
    if (count_alive(ALL) == 0)
        sfRenderWindow_close(WIN.window);
}

void print_framerate(void)
{
    static int first = 1;
    static sfClock *clock;
    sfTime elapsed;
    static int fps = 0;

    if (first == 1) {
        clock = sfClock_create();
        first = 0;
    }
    elapsed = sfClock_getElapsedTime(clock);
    if (sfTime_asSeconds(elapsed) >= 1) {
        my_put_nbr(fps);
        my_putchar('\n');
        fps = 0;
        sfClock_restart(clock);
    } else
        fps++;
}
