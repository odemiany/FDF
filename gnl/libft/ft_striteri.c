/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemiany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 22:26:17 by odemiany          #+#    #+#             */
/*   Updated: 2016/12/13 19:49:41 by odemiany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int i;

	if ((s == NULL) || (f == NULL))
		return ;
	i = 0;
	while (*s)
	{
		f(i, &(*s));
		s++;
		i++;
	}
}
