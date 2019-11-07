/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knedzing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 13:45:53 by knedzing          #+#    #+#             */
/*   Updated: 2018/05/29 09:43:34 by knedzing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int c;
	int i;
	int j;

	c = -1;
	if (needle[0] == '\0')
	{
		return ((char*)haystack);
	}
	while (haystack[++c] != '\0')
	{
		i = -1;
		j = c - 1;
		while (haystack[++j] == needle[++i] && needle[i] != '\0')
			;
		if (needle[i] == '\0')
		{
			return ((char*)(haystack + c));
		}
	}
	return (NULL);
}
