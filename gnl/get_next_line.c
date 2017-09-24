/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemiany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 17:43:12 by odemiany          #+#    #+#             */
/*   Updated: 2017/09/20 15:44:48 by odemiany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_xstrjoin(char *s1, char *s2)
{
	char *str;
	char *str_tmp;
	char *s1_cp;

	if ((s1 == NULL) || (s2 == NULL))
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	str_tmp = str;
	s1_cp = s1;
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
	free(s1_cp);
	return (str);
}

int		make_ret_str(char *temp_line, char **line, char **saved)
{
	size_t j;

	j = 0;
	while ((temp_line[j] != '\n') && (temp_line[j] != '\0'))
		j++;
	*line = (char *)malloc(sizeof(char) * (j + 1));
	*line = ft_strncpy(*line, temp_line, j);
	line[0][j] = '\0';
	*saved = (char *)malloc(sizeof(char) * (ft_strlen(temp_line) - j + 1));
	if (temp_line[j] == '\n')
		j++;
	*saved = ft_strcpy(*saved, &(temp_line[j]));
	free(temp_line);
	return (1);
}

int		check(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (0);
		str++;
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	ssize_t		c;
	char		*temp_line;
	char		buff_line[BUFF_SIZE + 1];
	static char	*saved = "\0";

	if (fd < 0 || BUFF_SIZE > 100000 || line == NULL || read(fd, 0, 0) == -1)
		return (-1);
	c = 0;
	temp_line = (char *)malloc(sizeof(char));
	*temp_line = '\0';
	if (*saved)
		temp_line = ft_xstrjoin(temp_line, saved);
	while (check(temp_line) != 0)
	{
		if ((c = read(fd, buff_line, BUFF_SIZE)) < 0)
			return (-1);
		buff_line[c] = '\0';
		temp_line = ft_xstrjoin(temp_line, buff_line);
		if (c == 0 && *temp_line == '\0')
			return ((make_ret_str(temp_line, line, &saved)) - 1);
		if (c == 0)
			return (make_ret_str(temp_line, line, &saved));
	}
	return (make_ret_str(temp_line, line, &saved));
}
