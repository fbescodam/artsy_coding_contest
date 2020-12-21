#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void red () {
  printf("\033[1;31m");
}

void yellow () {
  printf("\033[1;33m");
}

void green () {
  printf("\033[0;32m");
}

void blue () {
  printf("\033[0;34m");
}

void magenta () {
  printf("\033[0;35m");
}

void cyan () {
  printf("\033[0;36m");
}

void reset () {
  printf("\033[0m");
}

int file_size(int fd)
{
	int size = 0;
	int res = 1;
	char c;
	while (res)
	{
		read(fd, &c, 1);
		if (c == 'Z')
			return(size);
		size++;
	}
	return (size);
}

void assign_colors(char *colors, int fd, int size)
{
		read(fd, colors, size);
}

void interpret_img(char *file_name)
{
	char buff;
	int res = 1;

	int fd = open(file_name, O_RDONLY);
	int size = file_size(fd);
	char colors[size + 1];
	colors[size] = 0;
	close (fd);
	fd = open(file_name, O_RDONLY);
	assign_colors(colors, fd, size);

	int i = 0;
	//skip newline character
	res = read(fd, &buff, 1);
	res = read(fd, &buff, 1);
 	while (res)
	{
		res = read(fd, &buff, 1);
		if (colors[i] == 'R')
			red();
		else
			reset();
		printf("%c", buff);
		i++;
	}

}

/*
int main()
{
	interpret_img("shroomboat.txt");
}
*/
