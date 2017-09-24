/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemiany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 20:28:09 by odemiany          #+#    #+#             */
/*   Updated: 2016/12/29 00:06:28 by odemiany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b_cp;

	b_cp = (unsigned char *)b;
	while (len)
	{
		*b_cp = (unsigned char)c;
		b_cp++;
		len--;
	}
	return (b);
}
