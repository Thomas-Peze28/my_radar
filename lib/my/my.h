/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** h file
*/

#ifndef MY_
    #define MY_

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int cat(char *filepath);
int my_compute_power_it(int nb, int p);
int my_atoi(const char *str);
char **my_str_to_word_array02(char const *str, char separator);
void free_word_array(char **words);

#endif /* MY_ */
