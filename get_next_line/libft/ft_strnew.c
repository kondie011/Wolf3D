/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knedzing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 07:52:10 by knedzing          #+#    #+#             */
/*   Updated: 2018/06/14 10:06:30 by knedzing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	int		c;

	c = -1;
	str = (char*)malloc(sizeof(*str) * (size + 1));
	if (str)
	{
		str = (char*)ft_memset(str, '\0', size + 1);
		return (str);
	}
	return (NULL);
}
