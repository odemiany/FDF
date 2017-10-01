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
	rotation_ox(matrix_data->matrix, matrix_data->columns * matrix_data->lines);
	rotation_oy(matrix_data->matrix, matrix_data->columns * matrix_data->lines);
	rotation_oz(matrix_data->matrix, matrix_data->columns * matrix_data->lines);
}

void	rotation_ox(double **matrix, size_t dimension)
{
	size_t i;

	if (X_ROT != 0)
	{
		i = 0;
		while (i < dimension)
		{
			matrix[i][1] = matrix[i][1] * cos(X_ROT) + matrix[i][2] * sin(X_ROT);
			matrix[i][2] = matrix[i][2] * cos(X_ROT) - matrix[i][1] * sin(X_ROT);
			i++;
		}
	}
}

void	rotation_oy(double **matrix, size_t dimension)
{
	size_t i;

	if (Y_ROT != 0)
	{
		i = 0;
		while (i < dimension)
		{
			matrix[i][0] = matrix[i][0] * cos(Y_ROT) + matrix[i][2] * sin(Y_ROT);
			matrix[i][2] = matrix[i][2] * cos(Y_ROT) - matrix[i][0] * sin(Y_ROT);
			i++;
		}
	}
}

void 	rotation_oz(double **matrix, size_t dimension)
{
	size_t i;

	if (Z_ROT != 0)
	{
		i = 0;
		while (i < dimension)
		{
			matrix[i][0] = matrix[i][0] * cos(Z_ROT) - matrix[i][1] * sin(Z_ROT);
			matrix[i][1] = matrix[i][0] * sin(Z_ROT) + matrix[i][1] * cos(Z_ROT);
			i++;
		}
	}
}
