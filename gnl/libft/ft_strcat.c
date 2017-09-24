/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemiany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 22:45:48 by odemiany          #+#    #+#             */
/*   Updated: 2016/11/30 23:02:25 by odemiany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *destination, const char *append)
{
	char *start_destination;

	start_destination = destination;
	while (*destination != '\0')
		destination++;
	while (*append != '\0')
	{
		*destination = *append;
		destination++;
		append++;
	}
	*destination = '\0';
	return (start_destination);
}
