/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knedzing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 09:33:54 by knedzing          #+#    #+#             */
/*   Updated: 2018/06/02 14:03:58 by knedzing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		c;
	char	*str;

	if (s && f)
	{
		c = ft_strlen(s);
		str = (char *)malloc(sizeof(*str) * (c + 1));
		c = -1;
		if (str)
		{
			while (s[++c])
			{
				str[c] = f(c, s[c]);
			}
			str[c] = '\0';
			return (str);
		}
	}
	return (NULL);
}
