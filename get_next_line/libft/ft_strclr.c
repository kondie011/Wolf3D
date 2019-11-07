/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knedzing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 08:25:10 by knedzing          #+#    #+#             */
/*   Updated: 2018/05/23 12:03:20 by knedzing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	int c;

	c = -1;
	if (s)
	{
		while (s[++c])
		{
			s[c] = '\0';
		}
	}
}