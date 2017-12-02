/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 05:51:13 by adaly             #+#    #+#             */
/*   Updated: 2017/01/21 05:51:14 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int which_int;

	which_int = 0;
	while (which_int < length)
	{
		f(tab[which_int]);
		which_int++;
	}
}
