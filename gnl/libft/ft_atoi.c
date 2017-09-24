/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemiany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 23:16:54 by odemiany          #+#    #+#             */
/*   Updated: 2016/12/28 22:59:16 by odemiany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int					sign;
	unsigned long int	res;

	sign = 1;
	res = 0;
	while ((*str == ' ') || (*str == '\t') || (*str == '\v') ||
			(*str == '\f') || (*str == '\r') || (*str == '\n'))
		str++;
	if ((*str == '-') || (*str == '+'))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		if (res >= 922337203685477580 && (*str - '0') > 7 && sign == 1)
			return (-1);
		else if (res >= 922337203685477580 && (*str - '0') > 8 && sign == -1)
			return (0);
		res = res * 10 + (*str - '0');
		str++;
	}
	return ((int)(res * sign));
}
