/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 00:45:48 by adaly             #+#    #+#             */
/*   Updated: 2017/01/23 15:23:02 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	if (alst && del)
	{
		del((*alst)->content, (*alst)->content_size);
		if ((*alst)->next)
		{
			del(((*alst)->next)->content, ((*alst)->next)->content_size);
			free((*alst)->next);
			(*alst)->next = NULL;
		}
		free(*alst);
		*alst = NULL;
	}
}
