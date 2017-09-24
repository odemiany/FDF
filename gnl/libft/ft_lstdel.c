/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemiany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 23:23:56 by odemiany          #+#    #+#             */
/*   Updated: 2016/12/28 23:28:25 by odemiany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;

	if (alst)
	{
		if (*alst)
		{
			while (*alst)
			{
				tmp = (*alst)->next;
				del((*alst)->content, (*alst)->content_size);
				free(*alst);
				(*alst) = 0;
				(*alst) = tmp;
			}
		}
	}
	else
		return ;
}
