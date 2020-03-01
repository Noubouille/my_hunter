/*
** EPITECH PROJECT, 2019
** struct
** File description:
** struct
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Types.h>
#include <stdlib.h>
#include <SFML/Window/Types.h>
#include <SFML/Window/Export.h>

void my_putchar(char c);
char *nb_tochar(int i);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int game(sfRenderWindow* window);

struct game
{
    sfRenderWindow* window;
    sfTime time;
    sfTexture* texture;
    sfTexture* object;
    sfTexture* object2;
    sfTexture* object3;
    sfTexture* object4;
    sfTexture* object5;
    sfTexture* object6;
    sfTexture* object7;
    sfTexture* object8;
    sfText* scorenb;
    sfText* scorenb2;
    sfText* vienb;
    sfText* vienb2;
    sfSprite* background;
    sfSprite* obj;
    sfFont* font;
    sfEvent event;
};

struct main_menu
{
    sfRenderWindow* window;
    sfTime time;
    sfTexture* textur;
    sfTexture* objec2;
    sfTexture* objec3;
    sfTexture* objec4;
    sfTexture* objec5;
    sfTexture* objec6;
    sfTexture* objec7;
    sfTexture* objec8;
    sfSprite* backgroun;
    sfSprite* obje;
    sfFont* font;
    sfText* title;
    sfText* footer;
    sfMusic* music;
    sfEvent event;
};