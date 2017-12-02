/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 13:34:42 by adaly             #+#    #+#             */
/*   Updated: 2017/06/10 20:16:11 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_precision(t_pfconv *current)
{
	char	*strs;
	char	*ints;
	char	*floats;

	ints = ft_strdup("xXuUiIoOdD");
	strs = ft_strdup("sS");
	floats = ft_strdup("gGfFaAeE");
	if (current)
	{
		if (ft_strchr(ints, current->type))
			ft_precision_integer(current);
		else if (ft_strchr(strs, current->type))
			ft_precision_string(current);
		else if (ft_strchr(floats, current->type))
			ft_precision_float(current, current->precision);
		if (ft_strchr(ints, current->type) || \
		ft_strchr(strs, current->type) || ft_strchr(floats, current->type))
			current->chars = ft_strlen(current->string);
	}
	free(ints);
	free(strs);
	free(floats);
}
