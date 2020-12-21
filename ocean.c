#include "headers.h"

void	draw_ocean(char **canvas)
{
	int		i;
	int		j;

	i = 0;
	while (i < CANVAS_H)
	{
		j = 0;
		while (j < CANVAS_W)
		{
			if (canvas_pos_is_empty(canvas, j, i))
			{
				canvas[i][j] = ' ';
			}
			j++;
		}
		i++;
	}
}
