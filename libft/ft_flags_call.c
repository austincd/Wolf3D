/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_call.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 16:56:14 by adaly             #+#    #+#             */
/*   Updated: 2017/06/10 20:20:02 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_flags_integer(t_pfconv *current)
{
	ft_hash(current);
	ft_zero(current);
	ft_space(current);
	ft_plus(current);
}

static void	ft_flags_float(t_pfconv *current)
{
	ft_hash(current);
	ft_space(current);
	ft_plus(current);
	ft_zero(current);
}

static void	ft_flags_other(t_pfconv *current)
{
	ft_hash(current);
	ft_space(current);
	ft_plus(current);
	ft_zero(current);
}

void		ft_flags(t_pfconv *current)
{
	char	**types;

	types = ft_build_types_alt();
	if (current)
	{
		if (ft_strchr(types[0], current->type))
			ft_flags_integer(current);
		else if (ft_strchr(types[1], current->type))
			ft_flags_float(current);
		else if (ft_strchr(types[2], current->type))
			ft_flags_other(current);
	}
	ft_strdel_plus(types + 0);
	ft_strdel_plus(types + 1);
	ft_strdel_plus(types + 2);
	free(types);
}
