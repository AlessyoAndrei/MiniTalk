/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 10:23:17 by abidian           #+#    #+#             */
/*   Updated: 2017/12/11 10:34:17 by abidian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *ret;
	t_list *org;

	org = f(lst);
	ret = org;
	while (lst->next)
	{
		ret->next = f(lst->next);
		ret = ret->next;
		lst = lst->next;
	}
	return (org);
}
