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
# define X_ANGLE 310
# define Y_ANGLE 300
# define Z_ANGLE 0
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"

typedef struct	s_matrix
{
	double		**matrix;
	size_t		lines;
	size_t		columns;
}				t_matrix;
typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_matrix	*matrix_ptr;
}				t_mlx;
typedef struct	s_line
{
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			sign_x;
	int			sign_y;
	int			error;
	int			error2;
	int			delta_x;
	int			delta_y;
	int			color;
	int			color2;
}				t_line;
void			fdf(char *filename);
void			create_matrix(t_matrix *matrix_data, char *filename);
void			fill_matrix(t_matrix *matrix_data, char *filename);
int				ft_isspace(char c);
size_t			count_columns(char *line);
int				get_altitude(char *line, size_t j);
int				get_color(char *line, size_t j);
int				hex_to_int(char *line);
void			rotate_matrix(t_matrix *matrix_data);
void			rotation_ox(double **matr, size_t dimension, double rad);
void			rotation_oy(double **matr, size_t dimension, double rad);
void			rotation_oz(double **matr, size_t dimension, double rad);
void			make_image(t_matrix *matrix_data, char *filename);
void			create_window(char *filename, t_mlx *mlx_data,
													t_matrix *matrix_data);
void			print_image(t_mlx *mlx_data, t_matrix *matrix_data);
void			print_line(double *current, double *next, t_mlx *mlx);
void			check_file(char *filename);
int				my_key_func(int keycode, void *param);
void			init_line_variables(t_line *line, double *current,
														double *next);
void			exit_error(char *line);
void			check_file(char *filename);
int				check_six_chars(char *line);
void			scale_matrix(t_matrix *matrix_data, double scale);
void			zoom_event(t_mlx *ptr, int key);
void			exit_event(t_mlx *ptr);
#endif
