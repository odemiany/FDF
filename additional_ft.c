/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_ft.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemiany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 19:18:50 by odemiany          #+#    #+#             */
/*   Updated: 2017/09/27 19:18:53 by odemiany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int 	hex_to_int(char *line)
{
	int mult;
	int res;
	int base;
	int counter;

	res = 0;
	base = 16 * 16 * 16 * 16 * 16;
	counter = 6;
	while (counter > 0)
	{
		if (*line == 'A' || *line == 'a')
			mult = 10;
		else if (*line == 'B' || *line == 'b')
			mult = 11;
		else if (*line == 'C' || *line == 'c')
			mult = 12;
		else if (*line == 'D' || *line == 'd')
			mult = 13;
		else if (*line == 'E' || *line == 'e')
			mult = 14;
		else if (*line == 'F' || *line == 'f')
			mult = 15;
		else
			mult = *line - '0';
		res = res + base * mult;
		line++;
		base /= 16;
		counter--;
	}
	return (res);
}

int		ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

void 	print(t_matrix *matrix_data)
{
	size_t i;

	i =0;
	while (i < matrix_data->columns * matrix_data->lines)
	{
		ft_putstr("x: ");
		ft_putnbr((int)matrix_data->matrix[i][0]);

		ft_putstr("\ny: ");
		ft_putnbr((int)matrix_data->matrix[i][1]);
		ft_putstr("\nz: ");
		ft_putnbr((int)matrix_data->matrix[i][2]);
		ft_putstr("\ncolor: ");
		ft_putnbr((int)matrix_data->matrix[i][3]);
		ft_putstr("\n----------------\n");
		i++;
	}
}
