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
	t_mlx			mlx_data;

	create_window(filename, &mlx_data, matrix_data);
	rotate_matrix(matrix_data);
	print_image(&mlx_data, matrix_data);
	mlx_hook(mlx_data.win_ptr, 2, 5, my_key_func, &mlx_data);
	mlx_loop((&mlx_data)->mlx_ptr);
}

void	create_window(char *filename, t_mlx *mlx_data, t_matrix *matrix_data)
{
	mlx_data->mlx_ptr = mlx_init();
	mlx_data->win_ptr = mlx_new_window(mlx_data->mlx_ptr, 1200, 1200, filename);
	mlx_data->matrix_ptr = matrix_data;
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
		if (line.x1 <= 1200 && line.y1 <= 1200)
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, line.x1, line.y1,
																	line.color);
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
	if (line.x2 <= 1200 && line.y2 <= 1200)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, line.x2, line.y2,
															  line.color2);
}

int		my_key_func(int key, void *param)
{
	t_mlx *ptr;

	ptr = (t_mlx *)param;
	if (key == 53)
		exit_event(ptr);
	else if (key == 24 || key == 27)
		zoom_event(ptr, key);
	else if (key > 122 && key < 127)
		move_event(ptr, key);
	return (0);
}
