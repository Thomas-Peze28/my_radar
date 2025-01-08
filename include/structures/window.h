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

#ifndef WINDOW_
    #define WINDOW_

    #define WIN ALL->parameters

    #include "plane.h"
    #include "tower.h"
    #include "simu.h"
    #include "corner.h"

typedef struct parameter_s {
    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfEvent event;
    sfTexture *bg_texture;
    sfSprite *bg_sprite;
} parameter_t;

void print_framerate(void);
void display_background(sfRenderWindow *renderWindow);

#endif /* WINDOW_ */
