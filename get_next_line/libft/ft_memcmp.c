/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knedzing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 14:21:26 by knedzing          #+#    #+#             */
/*   Updated: 2018/05/23 07:30:18 by knedzing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int c;

	c = -1;
	while (++c < (int)n)
	{
		if (*(unsigned char*)(s1 + c) != *(unsigned char*)(s2 + c))
		{
			return (*(unsigned char*)(s1 + c) - *(unsigned char*)(s2 + c));
		}
	}
	return (0);
}
