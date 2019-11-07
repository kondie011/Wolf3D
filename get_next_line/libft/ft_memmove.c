/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knedzing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 13:48:51 by knedzing          #+#    #+#             */
/*   Updated: 2018/06/08 09:52:31 by knedzing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp_d;
	unsigned char	*tmp_s;

	tmp_d = (unsigned char*)dst;
	tmp_s = (unsigned char*)src;
	if (tmp_s < tmp_d)
	{
		while (0 <= (int)--len)
		{
			tmp_d[len] = tmp_s[len];
		}
	}
	else
	{
		ft_memcpy(dst, src, len);
	}
	return (dst);
}
