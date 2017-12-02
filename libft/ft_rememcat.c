/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rememcat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 21:46:24 by adaly             #+#    #+#             */
/*   Updated: 2017/06/12 22:58:52 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	ft_rememcat(void **dst, void *src, uintmax_t dstsz, uintmax_t srcsz)
{
	void	*new;

	if (dst)
	{
		new = ft_memalloc(sizeof(char) * (dstsz + srcsz));
		if (new)
		{
			if (*dst && dstsz)
			{
				ft_memmove(new, *dst, dstsz);
			}
			else
				dstsz = 0;
			if (*dst)
				free(*dst);
			ft_memmove(new + dstsz, src, srcsz);
			*dst = new;
		}
	}
	return (dstsz + srcsz);
}
