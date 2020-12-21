#include "headers.h"

void	clear_canvas(char **canvas)
{
	int		i;
	int		j;

	i = 0;
	while (i < CANVAS_W)
	{
		j = 0;
		while (j < CANVAS_H)
		{
			canvas[i][j] = ' ';
			j++;
		}
		i++;
	}
	write(1, "\e[1;1H\e[2J", 10);
}

char	**init_canvas()
{
	char	**canvas;
	int		i;

	canvas = malloc(sizeof(char *) * CANVAS_W);
	i = 0;
	while (i < CANVAS_W)
	{
		canvas[i] = malloc(sizeof(char) * CANVAS_H);
		i++;
	}
	return (canvas);
}

void	draw_canvas(char **canvas)
{
	int		i;
	int		j;

	i = 0;
	while (i < CANVAS_H)
	{
		write(1, canvas[i], CANVAS_W);
		write(1, "\n", 1);
		i++;
	}
}

int		main(void)
{
	struct timespec	ts;
	char			**canvas;

	ts.tv_sec = 0;
	ts.tv_nsec = 1000000000 / FRAMERATE;
	canvas = init_canvas();
	clear_canvas(canvas);
	draw_canvas(canvas);
	nanosleep(&ts, &ts);
	main();
}
