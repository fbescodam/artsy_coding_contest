#include "headers.h"

char	*get_story_line(char *story)
{
	static char *last_pos;
	char		*new_pos;

	if (last_pos == 0)
		last_pos = story;
	new_pos = strchr(last_pos, '\n');
	if (new_pos)
	{
		new_pos++;
		last_pos = new_pos;
		return (new_pos);
	}
	return (NULL);
}

void	draw_beep_boop(char *story_line, char *beep_boop)
{
	int		to_beep_or_not_to_boop;
	int		line_length;
	char	*temp;
	char	temp_line[COLS + 1];
	int		y;

	temp = beep_boop;
	to_beep_or_not_to_boop = 0;
	if (story_line[3] == 'o')
	{
		temp = strchr(beep_boop, 'Z') + 2;
		to_beep_or_not_to_boop = 1;
	}
	else if (story_line[3] != 'e')
		to_beep_or_not_to_boop = 2;


	line_length = ft_strlen_nl(temp, COLS);
	if (to_beep_or_not_to_boop != 2)
		y = 4;
	else
		y = (LINES - get_amount_of_lines(beep_boop)) / 2;
	while (line_length > 1)
	{
		strncpy(temp_line, temp, line_length);
		temp_line[line_length] = '\0';
		if (to_beep_or_not_to_boop == 1)
			mvprintw(y, COLS - 10 - line_length, temp_line);
		else if (to_beep_or_not_to_boop == 2)
			mvprintw(y, (COLS - line_length) / 2, temp_line);
		else
			mvprintw(y, 10, temp_line);
		temp = temp + line_length + 1;
		line_length = ft_strlen_nl(temp, COLS);
		y++;
	}
}

int		draw_story(char *story, char *beep_boop, unsigned int frame)
{
	static int		part;
	static char		*story_line;
	static int		line_length;
	char			*temp;
	int				centered_x;

	if (frame == 0 || frame % 60 == 0)
	{
		temp = get_story_line(story);
		if (!temp)
			return (-1);
		line_length = ft_strlen_nl(temp, COLS);
		if (story_line)
			free(story_line);
		story_line = (char *)malloc(sizeof(char) * (line_length + 1));
		strncpy(story_line, temp, line_length);
		story_line[line_length] = '\0';
		part++;
	}
	if (story_line[0] == '$')
		draw_beep_boop(story_line, beep_boop);
	else
		mvprintw(LINES - 4, (COLS - line_length) / 2, story_line);
	return (part);
}
