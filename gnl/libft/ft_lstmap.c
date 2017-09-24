/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemiany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 23:37:14 by odemiany          #+#    #+#             */
/*   Updated: 2016/12/28 23:40:30 by odemiany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;

	new = 0;
	if (lst)
	{
		new = ft_lstnew((f(lst))->content, (f(lst))->content_size);
		if (lst->next)
			new->next = ft_lstmap(lst->next, f);
		return (new);
	}
	return (NULL);
}
