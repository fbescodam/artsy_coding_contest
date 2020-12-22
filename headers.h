#ifndef HEADERS_H
# define HEADERS_H

# define FRAMERATE 20

# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <time.h>
# include <curses.h>
# include <signal.h>

size_t	ft_strlen_nl(const char *s, size_t maxlen);
int		get_file_size(int fd);
void	free_waves(int **waves);
int		**draw_ocean(int ended);
char	*read_file();
int		draw_story(char *story, char *beep_boop, unsigned int frame);
void	draw_beep_boop(char *story_line, char *beep_boop);

#endif
