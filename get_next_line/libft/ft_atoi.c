/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knedzing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:48:39 by knedzing          #+#    #+#             */
/*   Updated: 2018/05/31 10:28:07 by knedzing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		c;
	long	i;
	int		s;

	c = -1;
	i = 0;
	while ((str[++c] >= '\t' && str[c] <= '\r') || str[c] == ' ')
		;
	s = c;
	if (str[c] != '+' && str[c] != '-')
		--c;
	while (str[++c] && ft_isdigit(str[c]))
		i = (i * 10) + (str[c] - '0');
	if (i < 0 && str[s] != '-')
		return (-1);
	if (i < 0)
		return (0);
	if (str[s] == '-')
		return (-1 * i);
	else
		return (i);
}
