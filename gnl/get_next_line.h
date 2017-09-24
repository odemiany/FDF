/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odemiany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 17:44:37 by odemiany          #+#    #+#             */
/*   Updated: 2017/05/16 14:57:47 by odemiany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 39
# include <unistd.h>
# include <stdlib.h>

int		get_next_line(const int fd, char **line);
char	*ft_xstrjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t len);
void	ft_strdel(char **str);
#endif
