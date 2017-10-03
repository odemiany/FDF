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

int		hex_to_int(char *line)
{
	int mult;
	int res;
	int base;
	int counter;

	if (check_six_chars(line) == -1)
		return (DEFAULT_COLOR);
	res = 0;
	base = 16 * 16 * 16 * 16 * 16;
	counter = 6;
	while (counter > 0)
	{
		mult = *line - '0';
		mult = (*line == 'A' || *line == 'a') ? 10 : mult;
		mult = (*line == 'B' || *line == 'b') ? 11 : mult;
		mult = (*line == 'C' || *line == 'c') ? 12 : mult;
		mult = (*line == 'D' || *line == 'd') ? 13 : mult;
		mult = (*line == 'E' || *line == 'e') ? 14 : mult;
		mult = (*line == 'F' || *line == 'f') ? 15 : mult;
		res = res + base * mult;
		line++;
		base /= 16;
		counter--;
	}
	return (res);
}

int		check_six_chars(char *l)
{
	int		i;

	i = 0;
	while (i < 6)
	{
		if (l[i] && ((l[i] > 47 && l[i] < 58) || (l[i] > 64 && l[i] < 71) ||
				(l[i] > 96 && l[i] < 103)))
			i++;
		else
			return (-1);
	}
	return (0);
}

int		ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' ||
													c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

void	init_line_variables(t_line *line, double *current, double *next)
{
	line->x1 = (int)(current[0] * 20 + 100);
	line->y1 = (int)(current[1] * 20 + 100);
	line->x2 = (int)(next[0] * 20 + 100);
	line->y2 = (int)(next[1] * 20 + 100);
	line->delta_x = abs(line->x2 - line->x1);
	line->delta_y = abs(line->y2 - line->y1);
	line->sign_x = line->x1 < line->x2 ? 1 : -1;
	line->sign_y = line->y1 < line->y2 ? 1 : -1;
	line->error = line->delta_x - line->delta_y;
	line->color = (int)(current[3]);
	line->color2 = (int)(next[3]);
}
