/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knedzing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 10:43:07 by knedzing          #+#    #+#             */
/*   Updated: 2018/05/29 17:08:55 by knedzing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		c;
	char	*str;

	if (s)
	{
		c = ft_strlen(s);
		if (c >= (int)(len + start))
		{
			str = (char *)malloc(sizeof(*str) * (len + 1));
			if (str)
			{
				c = -1;
				while (++c < (int)len && s[start])
				{
					str[c] = s[start++];
				}
				str[c] = '\0';
				return (str);
			}
		}
	}
	return (NULL);
}
