/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finalize_other.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 22:51:25 by adaly             #+#    #+#             */
/*   Updated: 2017/06/10 20:04:24 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_finalize_wstr(t_pfconv *current)
{
	uintmax_t	lens[2];
	wchar_t		*final;

	final = NULL;
	lens[0] = ft_wstrlen((wchar_t*)current->widthstr);
	lens[1] = ft_wstrlen((wchar_t*)current->string);
	if (current)
	{
		if (ft_strequ(current->string, "(null)"))
			current->final = ft_strdup(current->string);
		else
		{
			final = (wchar_t*)ft_memalloc(sizeof(wchar_t) * \
			(lens[0] + lens[1]));
			if (final)
			{
				ft_memcpy(final, current->widthstr, \
				(sizeof(wchar_t) * lens[0]));
				ft_memcpy(final + lens[0], current->string, \
				(sizeof(wchar_t) * lens[1]));
			}
			current->final = (char*)final;
			current->chars = sizeof(wchar_t) * (lens[0] + lens[1]);
		}
	}
}
