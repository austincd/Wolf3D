/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mean.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 07:53:46 by adaly             #+#    #+#             */
/*   Updated: 2017/09/15 16:58:09 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**RETURNS THE MEAN OF TWO ELEMENTS ROUNDED TO THE NEAREST INT VALUE
*/

#include "libft.h"

intmax_t	ft_mean(intmax_t alpha, intmax_t beta)
{
	long double	f_mean;
	intmax_t	i_mean;

	f_mean = alpha + beta;
	f_mean /= 2;
	i_mean = f_mean + 0.5;
	return (i_mean);
}
