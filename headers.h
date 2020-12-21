#ifndef HEADERS_H
# define HEADERS_H

# define FRAMERATE 20
# define CANVAS_W 100
# define CANVAS_H 8

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <time.h>
# include <curses.h>
# include <math.h>

enum fg_colors {fg_black = 30, fg_red, fg_green, fg_yellow, fg_blue, fg_magenta, fg_cyan, fg_white, fg_b_black = 90, fg_b_red, fg_b_green, fg_b_yellow, fg_b_blue, fg_b_magenta, fg_b_cyan, fg_b_white};
enum bg_colors {bg_black = 40, bg_red, bg_green, bg_yellow, bg_blue, bg_magenta, bg_cyan, bg_white, bg_b_black = 100, bg_b_red, bg_b_green, bg_b_yellow, bg_b_blue, bg_b_magenta, bg_b_cyan, bg_b_white};

void	draw_ocean();

#endif
