#include "headers.h"


void	draw_robbie(int frame, struct timespec ts, int ***waves)
{
	char *robbie = read_file("DAMERMAID.TXT");
	int y = 2;
	int i = 0;
	int start_frame = frame;

	while (frame--)
	{
		*waves = draw_ocean();
		draw_beep_boop("ggggggg", robbie);
		refresh();
		nanosleep(&ts, &ts);
		clear();
	}
	free(robbie);
}


void	easel(struct timespec ts, char *story, char *beep_boop)
{
	int						**waves;
	static unsigned int		frame;

	waves = draw_ocean();
	if (draw_story(story, beep_boop, frame) < 0)
	{
		draw_robbie(frame, ts, &waves);
		free_waves(waves);
		return ;
	}
	frame++;
	refresh();
	nanosleep(&ts, &ts);
	clear();
	easel(ts, story, beep_boop);
}

void	setup_curses()
{
	WINDOW *scr;

	scr = initscr();
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
	leaveok(scr, 1);
}

void	handle_signal(int signal)
{
	endwin();
	refresh();
	clear();
	setup_curses();
}

int		main(void)
{
	struct timespec	ts;
	char			*story;
	char			*beep_boop;

	ts.tv_sec = 0;
	ts.tv_nsec = 1000000000 / FRAMERATE;
	setup_curses();
	story = read_file("THERETURNOFTHEROBOMERMAIDS.txt");
	beep_boop = read_file("beep_boop.txt");
	signal(SIGWINCH, handle_signal);
	if (story)
		easel(ts, story, beep_boop);
	else
		printw("Story read error");
	endwin();
	free(story);
	free(beep_boop);
	return (0);
}
