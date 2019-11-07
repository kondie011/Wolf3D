/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knedzing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 12:17:57 by knedzing          #+#    #+#             */
/*   Updated: 2018/05/21 14:03:41 by knedzing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		c;
	int		i;
	char	*str;

	if (s1 && s2)
	{
		c = ft_strlen(s1);
		i = ft_strlen(s2);
		str = (char *)malloc(sizeof(s1) * (c + i));
		if (str)
		{
			c = -1;
			while (s1[++c])
				str[c] = s1[c];
			i = -1;
			while (s2[++i])
				str[c++] = s2[i];
			str[c] = '\0';
			return (str);
		}
	}
	return (NULL);
}
