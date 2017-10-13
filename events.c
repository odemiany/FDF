#include "fdf.h"

void	zoom_event(t_mlx *ptr, int key)
{
	if (key == 27)
	{
		mlx_clear_window(ptr->mlx_ptr, ptr->win_ptr);
		scale_matrix(ptr->matrix_ptr, 0.75);
		print_image(ptr, ptr->matrix_ptr);
	}
	else if (key == 24)
	{
		mlx_clear_window(ptr->mlx_ptr, ptr->win_ptr);
		scale_matrix(ptr->matrix_ptr, 1.33333333333);
		print_image(ptr, ptr->matrix_ptr);
	}
}

void	exit_event(t_mlx *ptr)
{
	mlx_destroy_window(ptr->mlx_ptr, ptr->win_ptr);
	exit(0);
}

void	move_event(t_mlx *ptr, int key)
{
	int		delta_x;
	int 	delta_y;
	size_t	i;

	delta_x = 0;
	delta_y = 0;
	i = 0;
	if (key == 123 || key == 124)
		delta_x = (key == 124) ? 5 : -5;
	if (key == 125 || key == 126)
		delta_y = (key == 125) ? 5 : -5;
	while (i < (ptr->matrix_ptr->columns * ptr->matrix_ptr->lines))
	{
		ptr->matrix_ptr->matrix[i][0] += delta_x;
		ptr->matrix_ptr->matrix[i][1] += delta_y;
		i++;
	}
	mlx_clear_window(ptr->mlx_ptr, ptr->win_ptr);
	print_image(ptr, ptr->matrix_ptr);
}