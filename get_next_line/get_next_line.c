/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knedzing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 11:37:12 by knedzing          #+#    #+#             */
/*   Updated: 2018/06/22 13:19:00 by knedzing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_index(char *buff)
{
	int c;

	c = -1;
	while (buff[++c])
		if (buff[c] == '\n')
		{
			buff[c] = '\0';
			return (c);
		}
	return (-1);
}

static char	*join(char *buff, char *tab)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = 0;
	j = 0;
	if (buff)
		i = ft_strlen(buff);
	if (tab)
		j = ft_strlen(tab);
	ptr = (char *)malloc(sizeof(*ptr) * (i + j + 1));
	ft_memcpy(ptr, buff, i);
	ft_memcpy(ptr + i, tab, j);
	ptr[i + j] = '\0';
	free(buff);
	ft_bzero(tab, BUFF_SIZE + 1);
	return (ptr);
}

static int	verif(char **buff, char **tmp_buff, char **line)
{
	char	*ptr;
	int		index;

	*buff = join(*buff, *tmp_buff);
	index = get_index(*buff);
	if (index > -1)
	{
		*line = ft_strdup(*buff);
		ptr = *buff;
		*buff = ft_strdup(*buff + index + 1);
		free(ptr);
		return (1);
	}
	return (0);
}

static int	f(char *mem)
{
	free(mem);
	return (1);
}

int			get_next_line(int const fd, char **line)
{
	static char *buff[1];
	char		*b;
	int			result;
	int			r;

	b = ft_strnew(BUFF_SIZE);
	if ((!line || BUFF_SIZE <= 0 || fd < 0 || read(fd, b, 0) < 0) && f(b))
		return (-1);
	while ((r = read(fd, b, BUFF_SIZE)) > 0)
	{
		result = verif(&buff[fd], &b, line);
		if (f(b) && result == 1)
			return (1);
		b = ft_strnew(BUFF_SIZE);
	}
	if ((result = verif(&buff[fd], &b, line)) && f(b))
		return (1);
	else if (ft_strlen(buff[fd]) > 0 && f(b))
	{
		*line = ft_strdup(buff[fd]);
		ft_strdel(&buff[fd]);
		return (1);
	}
	free(b);
	return (result);
}
