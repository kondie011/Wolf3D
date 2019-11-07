/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knedzing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 07:28:00 by knedzing          #+#    #+#             */
/*   Updated: 2018/05/24 08:27:35 by knedzing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *mem;

	mem = (void*)malloc(sizeof(mem) * size);
	if (mem)
	{
		mem = ft_memset(mem, 0, size);
		return (mem);
	}
	return (NULL);
}
