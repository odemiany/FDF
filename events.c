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