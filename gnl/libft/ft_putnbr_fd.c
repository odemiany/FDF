/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemiany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 19:13:00 by odemiany          #+#    #+#             */
/*   Updated: 2016/12/29 20:31:39 by odemiany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int n_cp;

	if (fd >= 0)
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n_cp = -n;
		}
		else
			n_cp = n;
		if (n_cp < 10)
		{
			ft_putchar_fd(n_cp + '0', fd);
			return ;
		}
		ft_putnbr_fd(n_cp / 10, fd);
		ft_putnbr_fd(n_cp % 10, fd);
	}
}
