/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lastnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 19:58:39 by trecomps          #+#    #+#             */
/*   Updated: 2018/01/22 12:34:25 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *maillon;

	maillon = NULL;
	if ((content == NULL) || (*(void**)content == NULL) || (content_size == 0))
	{
		if (!(maillon = (t_list *)malloc(sizeof(t_list))))
			return (0);
		maillon->content_size = 0;
		maillon->content = NULL;
		return (maillon);
	}
	if (!(maillon = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!(maillon->content = ft_memalloc(content_size)))
		return (NULL);
	maillon->content = ft_memcpy(maillon->content, content, content_size);
	maillon->content_size = content_size;
	maillon->next = NULL;
	return (maillon);
}
