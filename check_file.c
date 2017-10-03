#include "fdf.h"

void	check_file(char *filename)
{
	int		fd;
	char	*line;
	size_t	first_line;

	if ((fd = open(filename, O_RDONLY)) == -1)
		exit_error("Problems with file\n");
	if (read(fd, 0, 0) == -1)
		exit_error("Couldn't read from file\n");
	get_next_line(fd, &line);
	if ((first_line = count_columns(line)) == 0)
		exit_error("No data found.\n");
	while (get_next_line(fd, &line))
	{
		if (count_columns(line) != first_line)
			exit_error("Wrong line length!\n");
	}
}

void	exit_error(char *line)
{
	ft_putstr(line);
	exit(1);
}