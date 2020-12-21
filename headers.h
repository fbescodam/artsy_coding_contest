#ifndef HEADERS_H
# define HEADERS_H

# define FRAMERATE 15
# define CANVAS_W 16
# define CANVAS_H 8

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <time.h>

typedef struct		s_canvas
{
	int		width;
	int		height;
	char	**chars;
	char	**bg_colors;
	char	**fg_colors;
}					t_canvas

int		canvas_pos_is_empty(char **canvas, int x, int y);

#endif
