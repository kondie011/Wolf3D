/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knedzing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 13:17:54 by knedzing          #+#    #+#             */
/*   Updated: 2018/05/24 09:43:33 by knedzing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		c;
	void	*tmp;

	tmp = dst;
	c = -1;
	while (++c < (int)n)
	{
		*(unsigned char*)(tmp + c) = *(unsigned char*)(src + c);
	}
	return (dst);
}
