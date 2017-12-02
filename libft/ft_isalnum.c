/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 23:19:27 by adaly             #+#    #+#             */
/*   Updated: 2017/01/21 02:08:59 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	int return_value;

	return_value = 0;
	if (ft_isalpha(c) == 1)
		return_value = 1;
	if (ft_isdigit(c) == 1)
		return_value = 1;
	return (return_value);
}
