/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemiany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 20:38:52 by odemiany          #+#    #+#             */
/*   Updated: 2016/12/29 20:47:53 by odemiany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	long	len;
	long	i;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s) - 1;
	i = 0;
	while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')
		len--;
	if (len > 0)
	{
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		{
			len--;
			i++;
		}
	}
	if (len == 0)
		return (NULL);
	return (ft_strsub(s, i, (len + 1)));
}
