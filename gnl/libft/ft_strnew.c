/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemiany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 19:28:00 by odemiany          #+#    #+#             */
/*   Updated: 2016/12/13 19:50:21 by odemiany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	str = NULL;
	str = (char *)malloc(size + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i <= size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
