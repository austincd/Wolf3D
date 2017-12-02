/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_import_options.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 02:14:33 by adaly             #+#    #+#             */
/*   Updated: 2017/06/10 20:07:55 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_import_options(t_pfconv *current, va_list args)
{
	if (current->width == -2)
	{
		current->width = va_arg(args, int);
		if (current->width < 0)
		{
			current->width *= -1;
			current->flags[0] = 1;
		}
	}
	if (current->precision == -2)
		current->precision = va_arg(args, int);
}
