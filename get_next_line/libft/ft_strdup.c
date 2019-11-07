/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knedzing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 12:15:20 by knedzing          #+#    #+#             */
/*   Updated: 2018/05/29 08:19:53 by knedzing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	int		c;

	c = ft_strlen(s1);
	cpy = (char *)malloc((c + 1) * sizeof(char));
	if (cpy == NULL)
	{
		return (NULL);
	}
	c = -1;
	while (s1[++c])
	{
		cpy[c] = s1[c];
	}
	cpy[c] = '\0';
	return (cpy);
}
