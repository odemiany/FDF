#include "fdf.h"

void	make_image(t_matrix *matrix_data, char *filename)
{
	t_mlx	mlx_data;

	create_window(filename, &mlx_data);
	print_image(&mlx_data, matrix_data);
}

void	create_window(char *filename, t_mlx *mlx_data)
{
	mlx_data->mlx_ptr = mlx_init();
	mlx_data->win_ptr = mlx_new_window(mlx_data->mlx_ptr, 1000, 1000, filename);
}

void	print_image(t_mlx *mlx_data, t_matrix *matrix_data)
{
	size_t i;

	i = 0;
	while (i < matrix_data->columns * matrix_data->lines - 1)
	{
		print_line);
		i++;
	}
}

void	print_line(int x1, int y1, int x2, int y2)
{
	int		x_dif;
	int		y_dif;
	int 	x_sign;
	int 	y_sign;
	int	err;
	int	err2;

	x_dif = abs(x2 - x1);
	y_dif = abs(y2 - y1);
	x_sign = x1 < x2 ? 1 : -1;
	y_sign = y1 < y2 ? 1 : -1;
	err = x_dif - y_dif;
	while (x1 != x2 || y1 != y2)
	{
		mlx_pixel_put(x1, y1);
		err2 = 2 * err;
		err = err2 > -y_dif ? -y_dif : err;
		x1 = err2 > -y_dif ? x1 + x_sign : x1;
		err = 34r
		if (err2 < x_dif)
		{
			err += x_dif;
			y1 += x_sign;
		}
	}
	mlx_pixel_put(x2, y2);
}
