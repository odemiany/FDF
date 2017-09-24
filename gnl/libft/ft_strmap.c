/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemiany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 22:40:37 by odemiany          #+#    #+#             */
/*   Updated: 2016/12/12 22:52:42 by odemiany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	i;

	if ((s == NULL) || (f == NULL))
		return (NULL);
	str = NULL;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		str[i] = f(*s);
		i++;
		s++;
	}
	str[i] = '\0';
	return (str);
}
