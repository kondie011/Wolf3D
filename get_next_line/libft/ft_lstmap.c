/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knedzing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 14:47:18 by knedzing          #+#    #+#             */
/*   Updated: 2018/06/01 16:07:13 by knedzing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*mlst;

	if (lst)
	{
		mlst = (t_list*)malloc(lst->content_size);
		if (!mlst)
			return (NULL);
		mlst = f(lst);
		lst = lst->next;
		mlst->next = ft_lstmap(lst, f);
		return (mlst);
	}
	return (NULL);
}
