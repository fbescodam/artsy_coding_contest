#include "headers.h"

void	draw_ocean(t_canvas *canvas)
{
	int		i;
	int		j;

	i = 0;
	while (i < CANVAS_H)
	{
		j = 0;
		while (j < CANVAS_W)
		{
			canvas->bg_colors[i][j] = bg_b_blue;
			canvas->lines[i][j] = 'A';
			canvas->fg_colors[i][j] = fg_b_white;
			if (canvas_pos_is_empty(canvas->lines, j, i))
			{

			}
			j++;
		}
		i++;
	}
}
