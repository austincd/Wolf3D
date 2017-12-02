/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_types.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 16:51:38 by adaly             #+#    #+#             */
/*   Updated: 2017/06/12 18:48:57 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		**ft_build_types(void)
{
	char	**types;
	int		index;

	index = 6;
	types = (char**)ft_memalloc(sizeof(char*) * index);
	types[0] = ft_strdup("sSpPdDiIoOuUxXcCeEfFgGaAnN%");
	types[1] = ft_strdup("di");
	types[2] = ft_strdup("fega");
	types[3] = ft_strdup("uxo");
	types[4] = ft_strdup("scpn%");
	types[5] = ft_strdup("DOU");
	return (types);
}

char		**ft_build_types_alt(void)
{
	char	**types;

	types = (char**)ft_memalloc(sizeof(char*) * 3);
	types[0] = ft_strdup("UXOIDuxoid");
	types[1] = ft_strdup("FGAEfgae");
	types[2] = ft_strdup("SCPNscpn%");
	return (types);
}

void		ft_free_types(char **types)
{
	ft_strdel_plus(types);
	ft_strdel_plus(types + 1);
	ft_strdel_plus(types + 2);
	ft_strdel_plus(types + 3);
	ft_strdel_plus(types + 4);
	ft_strdel_plus(types + 5);
	free(types);
}

void		ft_free_lengths(char **lengths)
{
	uintmax_t	counter;

	counter = 0;
	while (counter < 8)
	{
		ft_strdel_plus(lengths + counter);
		++counter;
	}
	free(lengths);
}

void		ft_free_types_alt(char **types)
{
	ft_strdel_plus(types);
	ft_strdel_plus(types + 1);
	ft_strdel_plus(types + 2);
	free(types);
}
