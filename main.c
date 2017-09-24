#include "fdf.h"

int		main(int argc, char ** argv)
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

	create_matrix(&matrix_data, filename);
	fill_matrix(&matrix_data, filename);
	rotate_matrix(&matrix_data);
	make_image(&matrix_data, filename);
	print(&matrix_data);
}

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
//int 	my_key_funct(int keycode, void *param)
//{
//	ft_putstr("key event ");
//	ft_putnbr(keycode);
//	if (keycode == 53)
//		mlx_destroy_window(((t_win_data *)param)->mlx_ptr, ((t_win_data *)param)->win_ptr);
//	return (0);
//}
//
//int 	main(void)
//{
//	void		*mlx;
//	void		*win;
//	t_win_data	win_data;
//
//	mlx = mlx_init();
//	win = mlx_new_window(mlx, 400, 400, "SAMPLE");
//	win_data.mlx_ptr = mlx;
//	win_data.win_ptr = win;
//	mlx_key_hook(win, my_key_funct, &(win_data));
//	mlx_loop(mlx);
//	return 0;
//}