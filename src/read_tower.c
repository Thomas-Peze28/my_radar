/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main for my_hunters
*/
#include "my.h"
#include "my_radar.h"

void count_entity(all_t *ALL, char *pathfile)
{
    FILE *file = fopen(pathfile, "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    ALL->simu_info.count_planes = 0;
    ALL->simu_info.count_towers = 0;
    if (file == NULL)
        return;
    read = getline(&line, &len, file);
    while (read != -1) {
        if (line[0] == 'A')
            ALL->simu_info.count_planes++;
        if (line[0] == 'T')
            ALL->simu_info.count_towers++;
        read = getline(&line, &len, file);
    }
    free(line);
    fclose(file);
}

void parse_line(all_t *ALL, const char *line, int t_index, int p_index)
{
    char **word_array = my_str_to_word_array02(line, ' ');

    if (word_array[0][0] == 'T') {
        TOW_ARR.position = (sfVector2i){
            my_atoi(word_array[1]),
            my_atoi(word_array[2])};
        TOW_ARR.radius = my_atoi(word_array[3]);
    }
    if (word_array[0][0] == 'A') {
        PLA_ARR.position = (sfVector2i){
            my_atoi(word_array[1]),
            my_atoi(word_array[2])};
        PLA_ARR.end_pos = (sfVector2i){
            my_atoi(word_array[3]),
            my_atoi(word_array[4])};
        PLA_ARR.speed = my_atoi(word_array[5]);
        PLA_ARR.delay = my_atoi(word_array[6]);
    }
    free_word_array(word_array);
}

void read_file(all_t *ALL, char *pathfile)
{
    FILE *file = fopen(pathfile, "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int index_tower = 0;
    int index_plane = 0;

    if (file == NULL)
        return;
    read = getline(&line, &len, file);
    while (read != -1) {
        parse_line(ALL, line, index_tower, index_plane);
        if (line[0] == 'T')
            index_tower++;
        if (line[0] == 'A')
            index_plane++;
        read = getline(&line, &len, file);
    }
    free(line);
    fclose(file);
}
