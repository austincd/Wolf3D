/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 00:50:36 by adaly             #+#    #+#             */
/*   Updated: 2017/01/23 15:25:16 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *nextone;
	t_list *ptr;

	if (alst && del)
	{
		ptr = *alst;
		while (ptr)
		{
			nextone = ptr->next;
			if (nextone)
				nextone = nextone->next;
			ft_lstdelone(&ptr, del);
			ptr = nextone;
		}
		*alst = NULL;
	}
}
