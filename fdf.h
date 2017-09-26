#ifndef FDF_H
# define FDF_H
# define DEFAULT_COLOR 255
# define X_ROT 0
# define Z_ROT 0
# define Y_ROT 0
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "mlx.h"
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
	size_t 	columns;
}				t_matrix;
void			fdf(char *filename);
void			create_matrix(t_matrix *matrix_data, char *filename);
void			fill_matrix(t_matrix *matrix_data, char *filename);
int 			ft_isspace(char c);
size_t 			count_columns(char *line);
int 			get_altitude(char *line, int j);
int 			get_color(char *line, int j);
int 			hex_to_int(char *line);
void			print(t_matrix *matrix_data);
void			rotate_matrix(t_matrix *matrix_data);
void 			rotation_ox(double **matrix, size_t dimension);
void 			rotation_oy(double **matrix, size_t dimension);
void 			rotation_oz(double **matrix, size_t dimension);
void			make_image(t_matrix *matrix_data, char *filename);
void			create_window(char *filename, t_mlx *mlx_data);
void			print_image(t_mlx *mlx_data, t_matrix *matrix_data);
void			print_line(double *current, double *next, t_mlx *mlx);
#endif