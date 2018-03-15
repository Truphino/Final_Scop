/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 21:33:40 by trecomps          #+#    #+#             */
/*   Updated: 2018/01/22 12:34:24 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*current;

	if (!*alst)
		return ;
	while (*alst)
	{
		del((*alst)->content, (*alst)->content_size);
		current = *alst;
		*alst = (*alst)->next;
		free(current);
	}
	*alst = NULL;
}
