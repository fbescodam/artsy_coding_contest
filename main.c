#include "headers.h"

void	easel(struct timespec ts)
{
	draw_ocean();
	refresh();
	nanosleep(&ts, &ts);
	clear();
	easel(ts);
}

int		main(void)
{
	struct timespec	ts;

	ts.tv_sec = 0;
	ts.tv_nsec = 1000000000 / FRAMERATE;
	initscr();
	start_color();
	use_default_colors();
	init_pair(1, COLOR_WHITE, -1);
	init_pair(2, COLOR_YELLOW, -1);
	init_pair(3, COLOR_RED, -1);
	init_pair(4, COLOR_GREEN, -1);
	init_pair(5, COLOR_BLUE, -1);
	init_pair(6, COLOR_MAGENTA, -1);
	init_pair(7, COLOR_CYAN, -1);
	init_pair(8, 112, -1);
	init_pair(9, 130, -1);
	init_pair(10, 135, -1);
	init_pair(11, 154, -1);
	init_pair(12, 160, -1);
	init_pair(13, 33, -1);
	init_pair(14, 14, -1);
	easel(ts);
	getch();
	endwin();
}
