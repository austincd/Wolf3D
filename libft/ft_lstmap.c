/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 00:09:53 by adaly             #+#    #+#             */
/*   Updated: 2017/01/19 08:00:26 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *lst_ptr;
	t_list *return_value;

	return_value = NULL;
	if (lst && f)
	{
		lst_ptr = f(lst);
		return_value = lst_ptr;
		lst = lst->next;
		while (lst && lst_ptr)
		{
			lst_ptr->next = f(lst);
			lst_ptr = lst_ptr->next;
			lst = lst->next;
		}
		if (lst == NULL)
			lst_ptr->next = NULL;
	}
	return (return_value);
}
