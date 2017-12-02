/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod_call.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 16:58:26 by adaly             #+#    #+#             */
/*   Updated: 2017/06/10 21:09:28 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_mod_integer(t_pfconv *current)
{
	ft_precision(current);
	ft_width(current);
}

static void	ft_mod_float(t_pfconv *current)
{
	ft_precision(current);
	ft_width(current);
}

static void	ft_mod_other(t_pfconv *current)
{
	ft_precision(current);
	ft_width(current);
}

void		ft_mod(t_pfconv *current)
{
	char	**types;

	types = ft_build_types_alt();
	if (types && current)
	{
		if (ft_strchr(types[0], current->type))
			ft_mod_integer(current);
		else if (ft_strchr(types[1], current->type))
			ft_mod_float(current);
		else if (ft_strchr(types[2], current->type))
			ft_mod_other(current);
	}
	ft_free_types_alt(types);
}
