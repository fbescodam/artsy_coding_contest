/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/21 17:11:24 by fbes          #+#    #+#                 */
/*   Updated: 2020/12/21 17:11:24 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void    clear_canvas()
{
    system("clear");
    printf("'\e[3J'");
}

void    draw_canvas()
{
    static int  x;
    int         i;

    i = 0;
    while (i < x)
    {
        printf(" ");
        i++;
    }
    printf("test");
    x++;
}

int     main(void)
{
    clear_canvas();
    draw_canvas();
    usleep(1000000 / FRAMERATE);
    main();
}