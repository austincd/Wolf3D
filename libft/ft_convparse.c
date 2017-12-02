/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convparse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 07:12:51 by adaly             #+#    #+#             */
/*   Updated: 2017/06/12 18:49:21 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_for_conversions(char *str, t_slist **first)
{
	t_slist		*entry;

	entry = NULL;
	while (str)
	{
		entry = ft_new_tslist(entry, NULL, 0);
		if (!*first)
			*first = entry;
		if (*str == '%')
		{
			entry->conversion = ft_conversion_parsing(&str);
		}
		else
		{
			entry->string = ft_strtcdup(str, '%');
			str = ft_strchr(str, '%');
		}
	}
}

void	ft_freeconv(t_pfconv *current)
{
	if (current)
	{
		if (current->flags)
			free(current->flags);
		if (current->string)
			ft_strdel_plus(&(current->string));
		if (current->widthstr)
			ft_strdel_plus(&(current->widthstr));
		if (current->prefix)
			ft_strdel_plus(&(current->prefix));
	}
	free(current);
}
