/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemiany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:14:40 by odemiany          #+#    #+#             */
/*   Updated: 2016/11/29 23:01:00 by odemiany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char *dst;
	char *temp_dst;

	temp_dst = NULL;
	temp_dst = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	dst = temp_dst;
	if (temp_dst == NULL)
		return (NULL);
	while (*str)
	{
		*temp_dst = *str;
		str++;
		temp_dst++;
	}
	*temp_dst = '\0';
	return (dst);
}
