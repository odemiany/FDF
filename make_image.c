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
	while (i < matrix_data->columns * matrix_data->lines)
	{
		mlx_pixel_put(mlx_data->mlx_ptr, mlx_data->win_ptr, mlx_data);
		i++;
	}
}

