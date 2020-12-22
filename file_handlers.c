#include "headers.h"

size_t	ft_strlen_nl(const char *s, size_t maxlen)
{
	size_t	i;

	i = 0;
	while (i < maxlen && s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

int		get_file_size(int fd)
{
	char	c;
	int 	size;

	size = 0;
	while (read(fd, &c, 1))
		size++;
	return (size);
}

char	*read_file(char *file)
{
	int		fd;
	int		size;
	char	*contents;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	size = get_file_size(fd);
	close(fd);
	fd = open(file, O_RDONLY);
	contents = (char *)malloc(sizeof(char) * (size + 1));
	read(fd, contents, size);
	contents[size] = '\0';
	close(fd);
	return (contents);
}
