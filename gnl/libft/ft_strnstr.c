/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemiany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 20:36:58 by odemiany          #+#    #+#             */
/*   Updated: 2016/12/29 02:03:35 by odemiany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*big_cp;
	char	*little_cp;
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && (i < len))
	{
		big_cp = (char *)(&(big[i]));
		little_cp = (char *)little;
		j = i;
		while ((*big_cp == *little_cp) && *big_cp && *little_cp && (j < len))
		{
			big_cp++;
			little_cp++;
			j++;
		}
		if (*little_cp == '\0')
			return ((char *)(&(big[i])));
		i++;
	}
	return (NULL);
}
