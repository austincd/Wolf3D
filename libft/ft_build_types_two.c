/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_types_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 18:52:55 by adaly             #+#    #+#             */
/*   Updated: 2017/06/12 23:24:49 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	**ft_build_types_two(void)
{
	char	**types;

	types = (char**)ft_memalloc(sizeof(char*) * 4);
	types[0] = ft_strdup("uxoUXO");
	types[1] = ft_strdup("diDI");
	types[2] = ft_strdup("feaFEA");
	types[3] = ft_strdup("sc%SC");
	return (types);
}

void	ft_free_types_two(char **types)
{
	ft_strdel_plus(types);
	ft_strdel_plus(types + 1);
	ft_strdel_plus(types + 2);
	ft_strdel_plus(types + 3);
	free(types);
}
