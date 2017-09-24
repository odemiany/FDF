/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemiany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 20:21:56 by odemiany          #+#    #+#             */
/*   Updated: 2016/12/29 20:12:50 by odemiany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *ptr;

	if ((ptr = (t_list *)malloc(sizeof(t_list))))
	{
		if (content)
		{
			ptr->content = ft_strsub(content, 0, content_size);
			if (!ptr->content)
				return (NULL);
			ptr->content_size = content_size;
		}
		else
		{
			ptr->content = 0;
			ptr->content_size = 0;
		}
		ptr->next = 0;
	}
	else
		return (NULL);
	return (ptr);
}
