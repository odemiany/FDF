/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemiany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 19:04:55 by odemiany          #+#    #+#             */
/*   Updated: 2017/09/27 19:05:01 by odemiany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	if (argc == 2)
		fdf(argv[1]);
	else
	{
		ft_putstr("usage: ./fdf /path/to/file\n");
		return (1);
	}
	return (0);
}

void	fdf(char *filename)
{
	t_matrix matrix_data;

	check_file(filename);
	create_matrix(&matrix_data, filename);
	fill_matrix(&matrix_data, filename);
	make_image(&matrix_data, filename);
}


