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
    if (WIN.event.type == sfEvtKeyPressed) {
        show_option(ALL);
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

int display_help(void)
{
    write(1, "Air traffic simulation panel\n", 29);
    write(1, "USAGE\n", 6);
    write(1, " ./my_radar [OPTIONS] path_to_script\n", 37);
    write(1, " path_to_script\tThe path to the script file.\n", 45);
    write(1, "OPTIONS\n", 8);
    write(1, " -h\t\tprint the usage and quit.\n", 31);
    write(1, "USER INTERACTIONS\n", 19);
    write(1, " 'L' key\t\tenable/disable hitboxes and areas.\n", 45);
    write(1, " 'S' key\t\tenable/disable sprites.\n", 34);
    return 0;
}

int main(int ac, char **argv)
{
    all_t ALL;

    if (ac != 2)
        return 84;
    if (argv[1][1] == 'h')
        return display_help();
    my_put_nbr(ac);
    count_entity(&ALL, argv[1]);
    init(&ALL, argv[1]);
    read_file(&ALL, argv[1]);
    game(&ALL);
    return 0;
}
