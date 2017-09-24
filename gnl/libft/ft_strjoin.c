/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemiany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 21:23:27 by odemiany          #+#    #+#             */
/*   Updated: 2016/12/13 21:39:56 by odemiany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *str;
	char *str_tmp;

	if ((s1 == NULL) || (s2 == NULL))
		return (NULL);
	str = NULL;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	str_tmp = str;
	while (*s1)
	{
		*str_tmp = *s1;
		str_tmp++;
		s1++;
	}
	while (*s2)
	{
		*str_tmp = *s2;
		str_tmp++;
		s2++;
	}
	*str_tmp = '\0';
	return (str);
}
