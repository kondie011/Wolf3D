/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knedzing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 14:31:04 by knedzing          #+#    #+#             */
/*   Updated: 2018/06/06 17:31:55 by knedzing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int c;
	int l;

	c = -1;
	if (needle[0] == '\0' || ft_strcmp(needle, haystack) == 0)
	{
		return ((char*)haystack);
	}
	l = ft_strlen(needle);
	while (haystack[++c] != '\0' && l <= (int)(len--))
	{
		if (haystack[c] == needle[0] && ft_memcmp(&haystack[c], needle, l) == 0)
			return ((char*)(haystack + c));
	}
	return (NULL);
}
