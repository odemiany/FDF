/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemiany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:52:45 by odemiany          #+#    #+#             */
/*   Updated: 2016/12/29 00:54:18 by odemiany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char b;

	b = '\0' + c;
	if (b == '\0')
	{
		while (*str)
			str++;
		return ((char *)str);
	}
	while (*str)
	{
		if (*str == b)
			return ((char*)str);
		str++;
	}
	return (NULL);
}
