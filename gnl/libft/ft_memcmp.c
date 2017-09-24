/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemiany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 20:49:00 by odemiany          #+#    #+#             */
/*   Updated: 2016/12/05 20:54:17 by odemiany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n)
	{
		if (*((unsigned char *)s1) == *((unsigned char *)s2))
		{
			s1++;
			s2++;
			n--;
		}
		else
			return (*((unsigned char *)s1) - *((unsigned char *)s2));
	}
	return (0);
}
