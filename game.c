/*
** EPITECH PROJECT, 2019
** game
** File description:
** game
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "struct.h"
#include <stdio.h>
#include <unistd.h>

int game(sfRenderWindow* window)
{
    struct game mygame;
    sfVideoMode mode = {1920, 1080, 32};
    sfClock* clock = sfClock_create();

    int seconds = 0;
    int score = 0;
    int vitesse = 10;
    int vie = 3;

    sfVector2f position;
    position.x = -200;
    position.y = 0;

    sfVector2f scale;
    scale.x = 1;
    scale.y = 1;

    sfVector2f scorepos;

    scorepos.x = 50;
    scorepos.y = 0;

    sfVector2f scorepos2;

    scorepos2.x = 350;
    scorepos2.y = 0;

    sfVector2f viepos;
    viepos.x = 1850;
    viepos.y = 0;

    sfVector2f viepos2;
    viepos2.x = 1700;
    viepos2.y = 0;

    mygame.texture = sfTexture_createFromFile("assets/pictures/bg.png", NULL);
    mygame.object2 = sfTexture_createFromFile("assets/nyancat/0s.png", NULL);
    mygame.object3 = sfTexture_createFromFile("assets/nyancat/1s.png", NULL);
    mygame.object4 = sfTexture_createFromFile("assets/nyancat/2s.png", NULL);
    mygame.object5 = sfTexture_createFromFile("assets/nyancat/3s.png", NULL);
    mygame.object6 = sfTexture_createFromFile("assets/nyancat/4s.png", NULL);
    mygame.object7 = sfTexture_createFromFile("assets/nyancat/5s.png", NULL);
    mygame.object8 = sfTexture_createFromFile("assets/nyancat/6s.png", NULL);
    mygame.font = sfFont_createFromFile("Gilberto.ttf");

    mygame.scorenb = sfText_create();
    sfText_setString(mygame.scorenb, "Your score :");
    sfText_setPosition(mygame.scorenb, scorepos);
    sfText_setFont(mygame.scorenb, mygame.font);
    sfText_setCharacterSize(mygame.scorenb, 100);

    mygame.scorenb2 = sfText_create();
    sfText_setString(mygame.scorenb2, nb_tochar(score));
    sfText_setPosition(mygame.scorenb2, scorepos2);
    sfText_setFont(mygame.scorenb2, mygame.font);
    sfText_setCharacterSize(mygame.scorenb2, 100);

    mygame.vienb = sfText_create();
    sfText_setString(mygame.vienb, nb_tochar(vie));
    sfText_setPosition(mygame.vienb, viepos);
    sfText_setFont(mygame.vienb, mygame.font);
    sfText_setCharacterSize(mygame.vienb, 100);

    mygame.vienb2 = sfText_create();
    sfText_setString(mygame.vienb2, "Life : ");
    sfText_setPosition(mygame.vienb2, viepos2);
    sfText_setFont(mygame.vienb2, mygame.font);
    sfText_setCharacterSize(mygame.vienb2, 100);

    mygame.obj = sfSprite_create();
    mygame.background = sfSprite_create();
    sfRenderWindow_setFramerateLimit(window, 60);

    sfSprite_setTexture(mygame.background, mygame.texture, sfTrue);
    sfSprite_setPosition(mygame.obj, position);
    sfSprite_setScale(mygame.obj, scale);

    while (sfRenderWindow_isOpen(window)) {
        position.x += vitesse;
        sfSprite_setPosition(mygame.obj, position);

        if (position.x > 1920) {
            vie = vie - 1;
            sfText_setString(mygame.vienb, nb_tochar(vie));
            position.x = -200;
            position.y = rand() % 800;
        }

        while (sfRenderWindow_pollEvent(window, &mygame.event)) {
            sfVector2i mousepos = sfMouse_getPositionRenderWindow(window);
            if (mygame.event.type == sfEvtClosed ||
            sfKeyboard_isKeyPressed(sfKeyEscape)) {
                sfRenderWindow_close(window);
            }
            else if (mygame.event.type == sfEvtMouseButtonPressed) {
                if (mousepos.x > position.x && mousepos.x < position.x + 300 &&
                mousepos.y > position.y && mousepos.y < position.y + 250) {
                    score = score + 1;
                    sfText_setString(mygame.scorenb2, nb_tochar(score));
                    vitesse = vitesse + 2;
                    position.x = -200;
                    position.y = rand() % 800;
                }
            }
        }
        if (vie == 0) {
            return (0);
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, mygame.background, NULL);
        sfRenderWindow_drawSprite(window, mygame.obj, NULL);
        sfRenderWindow_drawText(window, mygame.scorenb, NULL);
        sfRenderWindow_drawText(window, mygame.scorenb2, NULL);
        sfRenderWindow_drawText(window, mygame.vienb, NULL);
        sfRenderWindow_drawText(window, mygame.vienb2, NULL);
        sfRenderWindow_display(window);

        if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > 0.1) {
            if (seconds == 0) {
                sfSprite_setTexture(mygame.obj, mygame.object2, sfTrue);
                seconds = seconds + 1;
            }
            else if (seconds == 1) {
                sfSprite_setTexture(mygame.obj, mygame.object3, sfTrue);
                seconds = seconds + 1;
            }
            else if (seconds == 2) {
                sfSprite_setTexture(mygame.obj, mygame.object4, sfTrue);
                seconds = seconds + 1;
            }
            else if (seconds == 3) {
                sfSprite_setTexture(mygame.obj, mygame.object5, sfTrue);
                seconds = seconds + 1;
            }
            else if (seconds == 4) {
                sfSprite_setTexture(mygame.obj, mygame.object6, sfTrue);
                seconds = seconds + 1;
            }
            else if (seconds == 5) {
                sfSprite_setTexture(mygame.obj, mygame.object7, sfTrue);
                seconds = seconds + 1;
            }
            else if (seconds == 6) {
                sfSprite_setTexture(mygame.obj, mygame.object8, sfTrue);
                seconds = 0;
            }
            sfClock_restart(clock);
        }
    }

    sfSprite_destroy(mygame.obj);

    sfText_destroy(mygame.scorenb);
    sfText_destroy(mygame.scorenb2);
    sfText_destroy(mygame.vienb);
    sfText_destroy(mygame.vienb2);
    sfTexture_destroy(mygame.texture);
    sfTexture_destroy(mygame.object2);
    sfTexture_destroy(mygame.object3);
    sfTexture_destroy(mygame.object4);
    sfTexture_destroy(mygame.object5);
    sfTexture_destroy(mygame.object6);
    sfTexture_destroy(mygame.object7);
    sfTexture_destroy(mygame.object8);
    sfSprite_destroy(mygame.background);
    return (0);
}