/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemiany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 20:48:40 by odemiany          #+#    #+#             */
/*   Updated: 2016/12/19 20:07:13 by odemiany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_dig_count(unsigned int num)
{
	size_t			n;

	n = 1;
	if (num < 10)
		return (n);
	while (num > 9)
	{
		num = num / 10;
		n++;
	}
	return (n);
}

static char		*ft_transform(unsigned int num, char *str)
{
	size_t			n;

	n = ft_dig_count(num);
	str[n] = '\0';
	while (n)
	{
		str[n - 1] = (num % 10) + '0';
		num = num / 10;
		n--;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	unsigned int	n_cp;
	int				flag;
	char			*str;
	char			*str_cp;

	n_cp = (n < 0) ? -n : n;
	flag = (n < 0) ? 1 : 0;
	str = NULL;
	str = (char *)malloc(sizeof(char) * (ft_dig_count(n_cp) + flag + 1));
	if (str == NULL)
		return (NULL);
	str_cp = str;
	if (flag == 1)
	{
		*str_cp = '-';
		str_cp++;
	}
	ft_transform(n_cp, str_cp);
	return (str);
}
