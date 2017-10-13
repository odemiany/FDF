/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_fill_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemiany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 19:19:12 by odemiany          #+#    #+#             */
/*   Updated: 2017/09/27 19:19:14 by odemiany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_matrix(t_matrix *m_data, char *filename)
{
	int		fd;
	char	*test_line;
	size_t	i;
	size_t	lines;
	size_t	columns;

	fd = open(filename, O_RDONLY);
	i = 0;
	get_next_line(fd, &test_line);
	m_data->columns = count_columns(test_line);
	m_data->lines = 1;
	while (get_next_line(fd, &test_line))
		m_data->lines++;
	lines = m_data->lines;
	columns = m_data->columns;
	m_data->matrix = (double **)malloc(sizeof(double *) * lines * columns);
	while (i < lines * columns)
	{
		m_data->matrix[i] = (double *)malloc(sizeof(double) * 4);
		i++;
	}
	close(fd);
}

size_t	count_columns(char *line)
{
	size_t columns;

	columns = 0;
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

void	fill_matrix(t_matrix *matrix_data, char *filename)
{
	int		fd;
	size_t	i;
	size_t	j;
	size_t	column;
	char	*temp_line;

	fd = open(filename, O_RDONLY);
	i = 0;
	column = matrix_data->columns;
	while (i < matrix_data->lines)
	{
		get_next_line(fd, &temp_line);
		j = 0;
		while (j < column)
		{
			matrix_data->matrix[column * i + j][0] = j;
			matrix_data->matrix[column * i + j][1] = i;
			matrix_data->matrix[column * i + j][2] = get_altitude(temp_line, j);
			matrix_data->matrix[column * i + j][3] = get_color(temp_line, j);
			j++;
		}
		i++;
	}
	close(fd);
}

int		get_altitude(char *line, size_t j)
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

int		get_color(char *line, size_t j)
{
	while (j > 0)
	{
		while (*line && ft_isspace(*line))
			line++;
		while (*line && !ft_isspace(*line))
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
	if (!*line)
		return (DEFAULT_COLOR);
	if (line[1] == '0' && line[2] == 'x')
		return (hex_to_int(&line[3]));
	else
		return (DEFAULT_COLOR);
}
