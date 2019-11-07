/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knedzing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 15:05:48 by knedzing          #+#    #+#             */
/*   Updated: 2018/05/29 09:40:51 by knedzing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == (char)c)
		{
			return ((char*)(s + i));
		}
	}
	if (s[i] == (char)c)
	{
		return ((char*)(s + i));
	}
	return (NULL);
}
