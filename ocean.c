#include "headers.h"

void	draw_ocean()
{
	static int	frame;
	static int	wave_amount;
	static int	**waves;
	static int	i;

	if (wave_amount == 0)
	{
		wave_amount = COLS / 4;
		waves = (int **)malloc(sizeof(int *) * wave_amount);
		i = 0;
		while (i < wave_amount)
		{
			waves[i] = (int *)malloc(sizeof(int) * 2);
			waves[i][0] = 0;
			waves[i][1] = 0;
			i++;
		}
	}
	// printw("LINES: %d, COLS: %d, ", LINES, COLS);
	if (frame == 0)
	{
		i = 0;
		while (i < wave_amount)
		{
			waves[i] = (int *)malloc(sizeof(int) * 2);
			waves[i][0] = (rand() % (LINES - 1 + 1) + 1);
			waves[i][1] = (rand() % (COLS - 5 + 1) + 5);
			i += 2;
		}
	}
	if (frame == 20)
	{
		i = 1;
		while (i < wave_amount)
		{
			waves[i] = (int *)malloc(sizeof(int) * 2);
			waves[i][0] = (rand() % (LINES - 1 + 1) + 1);
			waves[i][1] = (rand() % (COLS - 5 + 1) + 5);
			i += 2;
		}
	}

	i = 0;
	while (i < wave_amount)
	{
		if (i % 2 || i == 0)
		{
			if (waves[i][0] > 0)
			{
				if (frame >= 0 && frame < 15)
					mvprintw(waves[i][0], waves[i][1], "_");
				else if (frame >= 15 && frame < 23)
					mvprintw(waves[i][0], waves[i][1], "~");
				else if (frame >= 23 && frame < 30)
					mvprintw(waves[i][0], waves[i][1], "=");
				else
					mvprintw(waves[i][0], waves[i][1], ".");
			}
		}
		else
		{
			if (waves[i][0] > 0)
			{
				if (frame >= 20 && frame < 30)
					mvprintw(waves[i][0], waves[i][1], "_");
				else if (frame >= 30 || frame < 7)
					mvprintw(waves[i][0], waves[i][1], "~");
				else if (frame >= 7 && frame < 10)
					mvprintw(waves[i][0], waves[i][1], "=");
				else if (frame >= 10 && frame < 20)
					mvprintw(waves[i][0], waves[i][1], ".");
			}
		}
		waves[i][1]--;
		i++;
	}
	//printw("wave_amount: %d, frame: %d\n", wave_amount, frame);
	frame++;
	if (frame > FRAMERATE * 2)
		frame = 0;
}
