/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knedzing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 07:53:47 by knedzing          #+#    #+#             */
/*   Updated: 2018/06/24 12:57:34 by knedzing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t c;

	c = 0;
	while ((s1[c] || s2[c]) && c < n)
	{
		if (s1[c] != s2[c])
		{
			return (*(unsigned char*)(s1 + c) - *(unsigned char*)(s2 + c));
		}
		c++;
	}
	return (0);
}
