/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knedzing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 14:09:03 by knedzing          #+#    #+#             */
/*   Updated: 2018/05/23 07:29:22 by knedzing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int i;

	i = -1;
	while (++i < (int)n)
	{
		if (*(unsigned char*)(s + i) == (unsigned char)c)
		{
			return ((void*)(s + i));
		}
	}
	return (NULL);
}
