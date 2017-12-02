/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 00:37:30 by adaly             #+#    #+#             */
/*   Updated: 2017/01/21 03:14:21 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	new = NULL;
	new = (t_list*)malloc(sizeof(t_list));
	if (new)
	{
		new->content = NULL;
		new->next = NULL;
		new->content_size = content_size;
		if (content)
		{
			new->content = (void*)malloc(content_size);
			ft_memcpy(new->content, content, content_size);
		}
		else
			new->content_size = 0;
	}
	return (new);
}
