/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main for my_hunters
*/
#include "my.h"
#include "my_radar.h"

void analyse_events(all_t *ALL)
{
    if (WIN.event.type == sfEvtClosed)
        sfRenderWindow_close(WIN.window);
    if (WIN.event.type == sfEvtKeyPressed
        && WIN.event.key.code == sfKeyL
        && ALL->simu_info.show_radius == 1) {
        ALL->simu_info.show_radius = 0;
        return;
    }
    if (WIN.event.type == sfEvtKeyPressed
        && WIN.event.key.code == sfKeyL
        && ALL->simu_info.show_radius == 0) {
        ALL->simu_info.show_radius = 1;
        return;
    }
}

void game(all_t *ALL)
{
    corner_t zones[4];
    sfClock *clock = sfClock_create();
    sfClock *clock_move = sfClock_create();
    sfTime time_move;
    float seconds;

    initialize_zones(zones);
    set(ALL);
    while (sfRenderWindow_isOpen(WIN.window)) {
        time_move = sfClock_getElapsedTime(clock_move);
        seconds = time_move.microseconds / 100000.0f;
        while (sfRenderWindow_pollEvent(WIN.window, &WIN.event)) {
            analyse_events(ALL);
        }
        assign_planes_to_zones(zones, ALL);
        init_clock(ALL, clock);
        print_framerate();
        display(ALL, clock_move, seconds);
    }
    sfRenderWindow_destroy(WIN.window);
}

int main(int ac, char **argv)
{
    all_t ALL;

    printf("nb arg : %d\n", ac);
    count_entity(&ALL, argv[1]);
    init(&ALL, argv[1]);
    read_file(&ALL, argv[1]);
    printf("TOWERS COUNT = %d\n", ALL.simu_info.count_towers);
    printf("PLANES COUNT = %d\n", ALL.simu_info.count_planes);
    game(&ALL);
    return 0;
}
