/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemiany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 23:55:34 by odemiany          #+#    #+#             */
/*   Updated: 2016/12/28 23:55:39 by odemiany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src,
		int c, size_t n)
{
	while (n > 0)
	{
		*((unsigned char*)dst) = *((unsigned char*)src);
		if (*((unsigned char*)src) != (unsigned char)c)
			n--;
		else
			return (++dst);
		dst++;
		src++;
	}
	return (NULL);
}
