/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knedzing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 10:21:53 by knedzing          #+#    #+#             */
/*   Updated: 2018/06/01 12:02:26 by knedzing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	set_sign(char *str, char s, int c)
{
	if (s == '-')
		str[++c] = s;
	return (c);
}

static void	ft_makestring(char *str, int n, int l)
{
	str[l] = '\0';
	while (n > 0)
	{
		str[--l] = (n % 10) + '0';
		n /= 10;
	}
}

char		*ft_itoa(int n)
{
	int		c;
	int		l;
	int		tmpn;
	char	*str;
	char	s;

	c = -1;
	l = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0 && ++l)
	{
		s = '-';
		n *= -1;
	}
	tmpn = n;
	while (tmpn > 0 && ++l)
		tmpn /= 10;
	if (!(str = (char*)malloc(sizeof(*str) * (l + 1))))
		return (NULL);
	c = set_sign(str, s, c);
	ft_makestring(str, n, l);
	return (str);
}
