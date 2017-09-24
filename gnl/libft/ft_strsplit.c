/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemiany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 01:53:45 by odemiany          #+#    #+#             */
/*   Updated: 2016/12/29 20:16:26 by odemiany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char		*split_c_from_start(const char *s, char c)
{
	const char		*tmp;

	if (s)
	{
		tmp = s;
		while (*tmp == c)
			tmp++;
		return (tmp);
	}
	else
		return (NULL);
}

static size_t			count_words(const char *s, char c)
{
	size_t			i;

	i = 0;
	while (*s)
	{
		while (*s != c && *s)
			s++;
		i++;
		s = split_c_from_start(s, c);
	}
	return (i);
}

static char				**make_arr(const char *s, char c)
{
	char			**arr;
	char			**buf;
	const char		*tmp;
	size_t			i;

	arr = ft_memalloc(sizeof(arr) * (count_words(s, c) + 1));
	if (!arr)
		return (NULL);
	buf = arr;
	while (*s)
	{
		tmp = s;
		i = 0;
		while (*s != c && *s)
		{
			i++;
			s++;
		}
		if (!(*(buf++) = ft_strsub(tmp, 0, i)))
			return (NULL);
		if (*s)
			s = split_c_from_start(s, c);
	}
	*(buf) = 0;
	return (arr);
}

char					**ft_strsplit(char const *s, char c)
{
	if (c && s)
		s = split_c_from_start(s, c);
	else
		return (NULL);
	return (make_arr(s, c));
}
