/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 07:51:54 by adaly             #+#    #+#             */
/*   Updated: 2017/09/15 16:57:26 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**FINDS AND RETURNS THE DIFFERENCE BETWEEN TWO SIGNED INTEGERS.
*/

#include "libft.h"

uintmax_t	ft_diff(intmax_t alpha, intmax_t beta)
{
	uintmax_t	diff;

	diff = ft_absval(alpha - beta);
	return (diff);
}
