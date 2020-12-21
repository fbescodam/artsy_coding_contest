#include "headers.h"

void	clear_canvas(char **canvas, char **colors)
{
	int		i;
	int		j;

	i = 0;
	while (i < CANVAS_H)
	{
		j = 0;
		while (j < CANVAS_W)
		{
			canvas[i][j] = ' ';
			colors[i][j] = ' ';
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

	canvas = malloc(sizeof(char *) * CANVAS_H);
	i = 0;
	while (i < CANVAS_H)
	{
		canvas[i] = malloc(sizeof(char) * CANVAS_W);
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

int		canvas_pos_is_empty(char **canvas, int x, int y)
{
	return (canvas[y][x] == ' ');
}

void	easel(struct timespec ts, char **canvas)
{
	clear_canvas(canvas);
	draw_canvas(canvas);
	nanosleep(&ts, &ts);
	easel(ts, canvas);
}

int		main(void)
{
	struct timespec	ts;
	char			**canvas;

	ts.tv_sec = 0;
	ts.tv_nsec = 1000000000 / FRAMERATE;
	canvas = init_canvas();
	easel(ts, canvas);
}
