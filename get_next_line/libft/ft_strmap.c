/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knedzing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 08:49:39 by knedzing          #+#    #+#             */
/*   Updated: 2018/05/29 10:57:31 by knedzing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		c;
	char	*str;

	if (s && f)
	{
		c = ft_strlen(s);
		str = (char *)malloc((c + 1) * sizeof(*str));
		if (str)
		{
			c = -1;
			while (s[++c])
			{
				str[c] = f(s[c]);
			}
			str[c] = '\0';
			return (str);
		}
	}
	return (NULL);
}
