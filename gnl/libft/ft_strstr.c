/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemiany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 20:25:19 by odemiany          #+#    #+#             */
/*   Updated: 2016/12/29 01:52:26 by odemiany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char *big_cp;
	char *little_cp;

	if (*little == '\0')
		return ((char *)big);
	while (*big)
	{
		big_cp = (char *)big;
		little_cp = (char *)little;
		while (*little_cp && *big_cp && *big_cp == *little_cp)
		{
			big_cp++;
			little_cp++;
		}
		if (*little_cp == '\0')
			return ((char *)big);
		big++;
	}
	return (NULL);
}
