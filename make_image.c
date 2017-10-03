/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemiany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 19:19:58 by odemiany          #+#    #+#             */
/*   Updated: 2017/09/27 20:53:17 by odemiany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	make_image(t_matrix *matrix_data, char *filename)
{
	t_mlx	mlx_data;

	create_window(filename, &mlx_data);
	print_image(&mlx_data, matrix_data);
	mlx_key_hook(mlx_data.win_ptr, my_key_func, &mlx_data);
	mlx_loop((&mlx_data)->mlx_ptr);
}

void	create_window(char *filename, t_mlx *mlx_data)
{
	mlx_data->mlx_ptr = mlx_init();
	mlx_data->win_ptr = mlx_new_window(mlx_data->mlx_ptr, 1000, 1000, filename);
}

void	print_image(t_mlx *mlx_data, t_matrix *m_data)
{
	size_t	i;
	size_t	lines;
	size_t	columns;

	i = 0;
	lines = m_data->lines;
	columns = m_data->columns;
	while (i < lines * columns - 1)
	{
		if (((i + 1) % columns) != 0)
			print_line(m_data->matrix[i], m_data->matrix[i + 1], mlx_data);
		if (i < columns * (lines - 1))
			print_line(m_data->matrix[i], m_data->matrix[i + columns],
																	mlx_data);
		i++;
	}
}

void	print_line(double *current, double *next, t_mlx *mlx)
{
	t_line	line;

	init_line_variables(&line, current, next);
	while (line.x1 != line.x2 || line.y1 != line.y2)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, line.x1, line.y1, 0x00FFFFFF);
		line.error2 = line.error * 2;
		if (line.error2 > -(line.delta_y))
		{
			line.error -= line.delta_y;
			line.x1 += line.sign_x;
		}
		if (line.error2 < line.delta_x)
		{
			line.error += line.delta_x;
			line.y1 += line.sign_y;
		}
	}
	mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, line.x2, line.y2, line.color2);
}

int		my_key_func(int keycode, void *param)
{
	if (keycode == 53)
	{
		mlx_destroy_window(((t_mlx *)param)->mlx_ptr,
						((t_mlx *)param)->win_ptr);
		exit(0);
	}
	return (0);
}
