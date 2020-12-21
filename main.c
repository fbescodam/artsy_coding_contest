/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/21 17:11:24 by fbes          #+#    #+#                 */
/*   Updated: 2020/12/21 18:14:49 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void    clear_canvas()
{
    write(1, "\e[1;1H\e[2J", 10);
}

void    draw_canvas()
{
    static int  x;
    int         i;

    i = 0;
    while (i < x)
    {
        write(1, " ", 1);
        i++;
    }
    write(1, "\x1B[31mTexting\033[0m\t\t", 19);
    write(1, "\n", 1);
    write(1, "\x1B[31mTexting\033[0m\t\t", 19);
    write(1, "\x1B[32mTexting\033[0m\t\t", 19);
    write(1, "\x1B[33mTexting\033[0m\t\t", 19);
    write(1, "\x1B[34mTexting\033[0m\t\t", 19);
    write(1, "\x1B[35mTexting\033[0m\n", 18);

    write(1, "\x1B[36mTexting\033[0m\t\t", 19);
    write(1, "\x1B[36mTexting\033[0m\t\t", 19);
    write(1, "\x1B[36mTexting\033[0m\t\t", 19);
    write(1, "\x1B[37mTexting\033[0m\t\t", 19);
    write(1, "\x1B[93mTexting\033[0m\n", 18);

    write(1, "\033[3;42;30mTexting\033[0m\t\t", 24);
    write(1, "\033[3;43;30mTexting\033[0m\t\t", 24);
    write(1, "\033[3;44;30mTexting\033[0m\t\t", 24);
    write(1, "\033[3;104;30mTexting\033[0m\t\t", 25);
    write(1, "\033[3;100;30mTexting\033[0m\n", 24);

    write(1, "\033[3;47;35mTexting\033[0m\t\t", 24);
    write(1, "\033[2;47;35mTexting\033[0m\t\t", 24);
    write(1, "\033[1;47;35mTexting\033[0m\t\t", 24);
    write(1, "\t\t", 2);
    write(1, "\n", 1);
    x++;
}

int     main(void)
{
    struct timespec	ts;

    ts.tv_sec  = 0;
	ts.tv_nsec = 1000000000 / FRAMERATE;
    clear_canvas();
    draw_canvas();
    nanosleep(&ts, &ts);
    main();
}
