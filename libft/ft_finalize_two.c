/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finalize_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 20:14:34 by adaly             #+#    #+#             */
/*   Updated: 2017/06/10 20:17:06 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_finalize_c(t_pfconv *current)
{
	char	*final;
	int		wide;

	wide = 0;
	if (current->widthstr)
		wide = ft_strlen(current->widthstr);
	final = NULL;
	final = ft_strnew(current->chars + wide);
	if (current->flags[0])
	{
		ft_memcpy(final, current->string, current->chars);
		if (wide)
			ft_memcpy(final + current->chars, current->widthstr, wide);
	}
	else
	{
		if (wide)
			ft_memcpy(final, current->widthstr, wide);
		ft_memcpy(final + wide, current->string, current->chars);
	}
	current->final = final;
	current->chars += wide;
}

void		ft_finalize_special(t_pfconv *current)
{
	char	*temp;

	temp = current->widthstr;
	current->widthstr = ft_strjoin("-", current->widthstr);
	ft_strdel_plus(&temp);
	temp = ft_strdup(current->string + 1);
	ft_strdel_plus(&(current->string));
	current->string = temp;
}
