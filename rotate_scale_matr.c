/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_matr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemiany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 19:20:24 by odemiany          #+#    #+#             */
/*   Updated: 2017/09/27 19:22:27 by odemiany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_matrix(t_matrix *matrix_data)
{
	size_t		size;
	double		**matr;

	matr = matrix_data->matrix;
	size = matrix_data->columns * matrix_data->lines;
	rotation_ox(matr, size, X_ANGLE * (M_PI / 180));
	rotation_oy(matr, size, Y_ANGLE * (M_PI / 180));
	rotation_oz(matr, size, Z_ANGLE * (M_PI / 180));
}

void	rotation_ox(double **matr, size_t dimension, double rad)
{
	size_t i;


	i = 0;
	while (i < dimension)
	{
		matr[i][1] = matr[i][1] * cos(rad) + matr[i][2] * sin(rad);
		matr[i][2] = matr[i][2] * cos(rad) - matr[i][1] * sin(rad);
		i++;
	}
}

void	rotation_oy(double **matr, size_t dimension, double rad)
{
	size_t i;

	i = 0;
	while (i < dimension)
	{
		matr[i][0] = matr[i][0] * cos(rad) + matr[i][2] * sin(rad);
		matr[i][2] = matr[i][2] * cos(rad) - matr[i][0] * sin(rad);
		i++;
	}
}

void	rotation_oz(double **matr, size_t dimension, double rad)
{
	size_t i;

	i = 0;
	while (i < dimension)
	{
		matr[i][0] = matr[i][0] * cos(rad) - matr[i][1] * sin(rad);
		matr[i][1] = matr[i][0] * sin(rad) + matr[i][1] * cos(rad);
		i++;
	}
}

void	scale_matrix(t_matrix *matrix_data, double scale)
{
	size_t	dimension;
	size_t	i;

	dimension = matrix_data->columns * matrix_data->lines;
	i =0;
	while (i < dimension)
	{
		matrix_data->matrix[i][0] *= scale;
		matrix_data->matrix[i][1] *= scale;
		matrix_data->matrix[i][2] *= scale;
		i++;
	}
}
