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
	easel(ts);
	getch();
	endwin();
}
