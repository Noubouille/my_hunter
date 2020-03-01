/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <SFML/Window/Export.h>
#include "struct.h"
#include <unistd.h>

int main(int ac, char** av)
{
    struct main_menu menu;
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        my_putstr("\n- Nyan Cat Hunt -\n\n");
        my_putstr("-  Your goal \n\n");
        my_putstr("   Kill all of the Nyan cats that go across the screen.\n");
        my_putstr("   Be careful! The speed of the Nyan cats will increase as");
        my_putstr("   you kill them!\n\n");
        my_putstr("   Good luck and have fun :)\n\n");
        return (0);
    }

    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow* window;
    sfClock* clock = sfClock_create();

    int seconds = 0;

    sfVector2f textpos;

    textpos.x = 500;
    textpos.y = 0;

    sfVector2f footerpos;

    footerpos.x = 670;
    footerpos.y = 900;

    sfVector2f position;
    position.x = 700;
    position.y = 100;

    sfVector2f scale;
    scale.x = 2;
    scale.y = 2;

    window = sfRenderWindow_create(mode, "Windows XP", sfResize| sfClose, NULL);
    menu.textur = sfTexture_createFromFile("assets/pictures/bg.png", NULL);
    menu.objec2 = sfTexture_createFromFile("assets/nyancat/0s.png", NULL);
    menu.objec3 = sfTexture_createFromFile("assets/nyancat/1s.png", NULL);
    menu.objec4 = sfTexture_createFromFile("assets/nyancat/2s.png", NULL);
    menu.objec5 = sfTexture_createFromFile("assets/nyancat/3s.png", NULL);
    menu.objec6 = sfTexture_createFromFile("assets/nyancat/4s.png", NULL);
    menu.objec7 = sfTexture_createFromFile("assets/nyancat/5s.png", NULL);
    menu.objec8 = sfTexture_createFromFile("assets/nyancat/6s.png", NULL);
    menu.music = sfMusic_createFromFile("assets/musics/nyancat.ogg");
    menu.font = sfFont_createFromFile("Gilberto.ttf");

    menu.title = sfText_create();
    sfText_setString(menu.title, "Nyan Cat Hunt");
    sfText_setPosition(menu.title, textpos);
    sfText_setFont(menu.title, menu.font);
    sfText_setCharacterSize(menu.title, 300);

    menu.footer = sfText_create();
    sfText_setString(menu.footer, "Press ENTER bouton to play");
    sfText_setPosition(menu.footer, footerpos);
    sfText_setFont(menu.footer, menu.font);
    sfText_setCharacterSize(menu.footer, 100);
    menu.obje = sfSprite_create();
    menu.backgroun = sfSprite_create();
    sfRenderWindow_setFramerateLimit(window, 60);

    sfSprite_setTexture(menu.backgroun, menu.textur, sfTrue);
    sfSprite_setPosition(menu.obje, position);
    sfSprite_setScale(menu.obje, scale);
    sfMusic_setLoop(menu.music, sfTrue);
    sfMusic_play(menu.music);


    while (sfRenderWindow_isOpen(window)) {
        position.x += 0;

        sfSprite_setPosition(menu.obje, position);

        while (sfRenderWindow_pollEvent(window, &menu.event)) {
            if (menu.event.type == sfEvtClosed ||
            sfKeyboard_isKeyPressed(sfKeyEscape)) {
                sfRenderWindow_close(window);
            }
            else if (menu.event.type == sfEvtClosed ||
            sfKeyboard_isKeyPressed(sfKeyReturn)) {
                game(window);
            }
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, menu.backgroun, NULL);
        sfRenderWindow_drawSprite(window, menu.obje, NULL);
        sfRenderWindow_drawText(window, menu.title, NULL);
        sfRenderWindow_drawText(window, menu.footer, NULL);
        sfRenderWindow_display(window);

        if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > 0.1) {
            if (seconds == 0) {
                sfSprite_setTexture(menu.obje, menu.objec2, sfTrue);
                seconds = seconds + 1;
            }
            else if (seconds == 1) {
                sfSprite_setTexture(menu.obje, menu.objec3, sfTrue);
                seconds = seconds + 1;
            }
            else if (seconds == 2) {
                sfSprite_setTexture(menu.obje, menu.objec4, sfTrue);
                seconds = seconds + 1;
            }
            else if (seconds == 3) {
                sfSprite_setTexture(menu.obje, menu.objec5, sfTrue);
                seconds = seconds + 1;
            }
            else if (seconds == 4) {
                sfSprite_setTexture(menu.obje, menu.objec6, sfTrue);
                seconds = seconds + 1;
            }
            else if (seconds == 5) {
                sfSprite_setTexture(menu.obje, menu.objec7, sfTrue);
                seconds = 0;
            }
            else if (seconds == 6) {
                sfSprite_setTexture(menu.obje, menu.objec8, sfTrue);
                seconds = 0;
            }
            sfClock_restart(clock);
        }
    }

    sfSprite_destroy(menu.obje);
    sfText_destroy(menu.title);
    sfText_destroy(menu.footer);
    sfTexture_destroy(menu.textur);
    sfTexture_destroy(menu.objec2);
    sfTexture_destroy(menu.objec3);
    sfTexture_destroy(menu.objec4);
    sfTexture_destroy(menu.objec5);
    sfTexture_destroy(menu.objec6);
    sfTexture_destroy(menu.objec7);
    sfTexture_destroy(menu.objec8);
    sfMusic_destroy(menu.music);
    sfSprite_destroy(menu.backgroun);
    sfRenderWindow_destroy(window);
    return (0);
}