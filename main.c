#include "headers.h"

void	clear_canvas(t_canvas *canvas)
{
	int		i;
	int		j;

	i = 0;
	while (i < CANVAS_H)
	{
		j = 0;
		while (j < CANVAS_W)
		{
			canvas->lines[i][j] = ' ';
			j++;
		}
		i++;
	}
	write(1, "\e[1;1H\e[2J", 10);
}

t_canvas	*init_canvas()
{
	t_canvas	*canvas;
	int			i;

	canvas = (t_canvas *)malloc(sizeof(t_canvas));
	canvas->lines = (char **)malloc(sizeof(char *) * CANVAS_H);
	canvas->bg_colors = (char **)malloc(sizeof(char *) * CANVAS_H);
	canvas->fg_colors = (char **)malloc(sizeof(char *) * CANVAS_H);
	i = 0;
	while (i < CANVAS_H)
	{
		canvas->lines[i] = (char *)malloc(sizeof(char) * CANVAS_W);
		canvas->bg_colors[i] = (char *)malloc(sizeof(char) * CANVAS_W);
		canvas->fg_colors[i] = (char *)malloc(sizeof(char) * CANVAS_W);
		i++;
	}
	return (canvas);
}

void	draw_canvas(t_canvas *canvas)
{
	int		i;
	int		j;
	int		k;
	int		size;
	char	*temp;

	size = CANVAS_H * CANVAS_W;
	i = 0;
	while (i < CANVAS_H)
	{
		j = 0;
		while (j < CANVAS_W)
		{
			if (canvas->bg_colors[i][j] > 99)
				size += 13;
			else
				size += 12;
			j++;
		}
		i++;
	}
	temp = (char *)malloc(sizeof(char) * size * 1000);
	temp[size] = '\0';
	if (!temp)
		return;
	k = 0;
	i = 0;
	while (i < CANVAS_H)
	{
		j = 0;
		while (j < CANVAS_W)
		{
			sprintf(temp + k, "\033[%d;%dm%c\033[0m", canvas->bg_colors[i][j], canvas->fg_colors[i][j], canvas->lines[i][j]);
			if (canvas->bg_colors[i][j] > 99)
				k += 14;
			else
				k += 13;
			j++;
		}
		sprintf(temp + k, "\n");
		k++;
		i++;
	}
	write(1, temp, size);
	free(temp);
}

int		canvas_pos_is_empty(char **canvas, int x, int y)
{
	return (canvas[y][x] == ' ');
}

void	easel(struct timespec ts, t_canvas *canvas)
{
	clear_canvas(canvas);
	draw_ocean(canvas);
	draw_canvas(canvas);
	nanosleep(&ts, &ts);
	easel(ts, canvas);
}

int		main(void)
{
	struct timespec	ts;
	t_canvas		*canvas;

	ts.tv_sec = 0;
	ts.tv_nsec = 1000000000 / FRAMERATE;
	canvas = init_canvas();
	easel(ts, canvas);
}
