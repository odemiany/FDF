/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemiany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 23:20:59 by odemiany          #+#    #+#             */
/*   Updated: 2016/11/30 23:31:16 by odemiany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *destination, const char *append, size_t n)
{
	char *start_destination;

	start_destination = destination;
	while (*destination)
		destination++;
	while ((n > 0) && *append)
	{
		*destination = *append;
		destination++;
		append++;
		n--;
	}
	*destination = '\0';
	return (start_destination);
}
