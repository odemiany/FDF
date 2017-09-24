#include "fdf.h"

void	create_matrix(t_matrix  *matrix_data, char *filename)
{
	int 	fd;
	char 	*test_line;
	size_t i;

	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		ft_putstr("Problems with file!\n");
		exit(1);
	}
	i = 0;
	matrix_data->lines = 0;
	test_line = NULL;
	get_next_line(fd, &test_line);
	if (test_line != NULL)
		matrix_data->lines++;
	matrix_data->columns = count_columns(test_line);
	while (get_next_line(fd, &test_line))
		matrix_data->lines++;
	matrix_data->matrix = (double **)malloc(sizeof(double *) * matrix_data->lines * matrix_data->columns);
	while (i < matrix_data->lines * matrix_data->columns)
	{
		matrix_data->matrix[i] = (double *)malloc(sizeof(double) * 4);
		i++;
	}
	close(fd);
}

void	fill_matrix(t_matrix *matrix_data, char *filename)
{
	int		fd;
	size_t	i;
	size_t 	j;
	char 	*temp_line;

	fd = open(filename, O_RDONLY);
	i = 0;
	while (i < matrix_data->lines)
	{
		get_next_line(fd, &temp_line);
		j = 0;
		while (j < matrix_data->columns)
		{
			matrix_data->matrix[matrix_data->columns * i + j][0] = j;
			matrix_data->matrix[matrix_data->columns * i + j][1] = i;
			matrix_data->matrix[matrix_data->columns * i + j][2] = get_altitude(temp_line, j);
			matrix_data->matrix[matrix_data->columns * i + j][3] = get_color(temp_line, j);
			j++;
		}
		i++;
	}
	close(fd);
}

int		get_altitude(char *line, int j)
{
	while (j > 0)
	{
		while (*line && ft_isspace(*line))
			line++;
		while (*line && !ft_isspace(*line))
			line++;
		j--;
	}
	return (ft_atoi(line));
}

int 	get_color(char *line, int j)
{
	while (j > 0)
	{
		while (*line && ft_isspace(*line))
			line++;
		while(*line && !ft_isspace(*line))
			line++;
		j--;
	}
	while (*line && ft_isspace(*line))
		line++;
	while (*line && *line != ',')
	{
		line++;
		if (ft_isspace(*line))
			return (DEFAULT_COLOR);
	}
	if (line[1] == '0' && line[2] == 'x')
		return(hex_to_int(&line[3]));
	else
		return (DEFAULT_COLOR);
}

size_t 	count_columns(char *line)
{
	size_t columns;

	columns = 0;
	if (line == NULL)
		return (0);
	while (*line)
	{
		while (*line && ft_isspace(*line))
			line++;
		if (*line)
			columns++;
		while (*line && !ft_isspace(*line))
			line++;
	}
	return (columns);
}