/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tslist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 05:48:05 by adaly             #+#    #+#             */
/*   Updated: 2017/06/04 15:17:30 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_slist		*ft_new_tslist(t_slist *previous, void *content, \
unsigned long long size)
{
	t_slist	*new;

	new = (t_slist*)ft_memalloc(sizeof(t_slist));
	if (new)
	{
		new->size = size;
		new->string = content;
		new->next = NULL;
		new->conversion = NULL;
		if (previous)
		{
			previous->next = new;
		}
	}
	return (new);
}
