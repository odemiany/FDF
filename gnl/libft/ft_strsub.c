/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemiany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 21:05:52 by odemiany          #+#    #+#             */
/*   Updated: 2016/12/29 01:29:23 by odemiany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*array;

	i = 0;
	array = NULL;
	if (s)
	{
		array = (char *)malloc(sizeof(*s) * len + 1);
		if (array != NULL)
		{
			while (len)
			{
				array[i] = s[start];
				i++;
				start++;
				len--;
			}
			array[i] = '\0';
			return (array);
		}
	}
	return (NULL);
}
