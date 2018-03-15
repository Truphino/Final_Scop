/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 21:46:22 by trecomps          #+#    #+#             */
/*   Updated: 2018/01/22 12:34:25 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *temp;
	t_list *current;
	t_list *beg;

	if (f && lst)
	{
		beg = f(lst);
		current = beg;
		lst = lst->next;
		while (lst)
		{
			temp = f(lst);
			current->next = temp;
			current = current->next;
			lst = lst->next;
		}
		return (beg);
	}
	return (NULL);
}
