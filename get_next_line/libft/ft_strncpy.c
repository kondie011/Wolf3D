/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knedzing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 11:58:59 by knedzing          #+#    #+#             */
/*   Updated: 2018/05/29 09:05:56 by knedzing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int c;

	c = -1;
	while (src[++c] != '\0' && c < (int)len)
	{
		dst[c] = src[c];
	}
	if (ft_strlen(src) < len)
	{
		dst[c] = '\0';
		while (++c < (int)len)
			dst[c] = '\0';
	}
	return (dst);
}
