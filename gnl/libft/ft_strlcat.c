/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemiany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 21:33:57 by odemiany          #+#    #+#             */
/*   Updated: 2016/12/29 21:33:59 by odemiany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	size_t	i;
	size_t	lend;
	size_t	lens;

	lend = ft_strlen(dst);
	lens = ft_strlen(src);
	if (size == 0)
		return (lens);
	if ((size - 1) < lend)
		return (size + lens);
	i = 0;
	while (dst[i])
		i++;
	size = size + i;
	while (*src && i < (size - lend - 1))
		dst[i++] = *(src++);
	dst[i] = 0;
	return (lend + lens);
}
