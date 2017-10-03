/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemiany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 19:03:52 by odemiany          #+#    #+#             */
/*   Updated: 2017/09/27 19:03:55 by odemiany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define DEFAULT_COLOR 255
# define X_ROT 300 * (M_PI / 180)
# define Y_ROT 0 * (M_PI / 180)
# define Z_ROT 0 * (M_PI / 180)
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_mlx;
typedef struct	s_matrix
{
	double	**matrix;
	size_t	lines;
	size_t	columns;
}				t_matrix;
typedef struct 	s_line
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int 	signX;
	int 	signY;
	int 	error;
	int 	error2;
	int 	deltaX;
	int 	deltaY;
	int 	color;
	int 	color2;
}				t_line;
void			fdf(char *filename);
void			create_matrix(t_matrix *matrix_data, char *filename);
void			fill_matrix(t_matrix *matrix_data, char *filename);
int				ft_isspace(char c);
size_t			count_columns(char *line);
int				get_altitude(char *line, int j);
int				get_color(char *line, int j);
int				hex_to_int(char *line);
void			rotate_matrix(t_matrix *matrix_data);
void			rotation_ox(double **matrix, size_t dimension);
void			rotation_oy(double **matrix, size_t dimension);
void			rotation_oz(double **matrix, size_t dimension);
void			make_image(t_matrix *matrix_data, char *filename);
void			create_window(char *filename, t_mlx *mlx_data);
void			print_image(t_mlx *mlx_data, t_matrix *matrix_data);
void			print_line(double *current, double *next, t_mlx *mlx);
void			check_file(char *filename);
int 			my_key_func(int keycode, void *param);
void			init_line_variables(t_line *line, double *current, double *next);
void			exit_error(char *line);
void			check_file(char *filename);
#endif
