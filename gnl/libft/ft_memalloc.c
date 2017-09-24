/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemiany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 23:22:02 by odemiany          #+#    #+#             */
/*   Updated: 2016/12/28 23:52:56 by odemiany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void			*ptr;
	unsigned char	*ptr_cp;

	ptr = NULL;
	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	ptr_cp = (unsigned char *)ptr;
	while (size)
	{
		*ptr_cp = 0;
		ptr_cp++;
		size--;
	}
	return (ptr);
}
