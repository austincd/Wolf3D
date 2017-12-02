/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 07:14:18 by adaly             #+#    #+#             */
/*   Updated: 2017/07/05 01:33:06 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*freed_mem;

	freed_mem = NULL;
	freed_mem = (void*)malloc(size);
	if (freed_mem)
		ft_bzero(freed_mem, size);
	return (freed_mem);
}
