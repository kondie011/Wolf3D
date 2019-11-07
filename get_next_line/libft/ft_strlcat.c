/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knedzing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 09:12:57 by knedzing          #+#    #+#             */
/*   Updated: 2018/05/30 18:17:52 by knedzing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int	c;
	int	i;
	int	k;

	k = -1;
	c = ft_strlen(dst);
	i = ft_strlen(src);
	while (src[++k] && (k + c + 1) < (int)dstsize)
	{
		dst[k + c] = src[k];
	}
	dst[c + k] = '\0';
	if ((i + c) < (int)dstsize)
		return (k + c);
	else if ((int)dstsize <= c)
		return (i + (int)dstsize);
	else
		return (c + i);
}
