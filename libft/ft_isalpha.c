/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 21:09:44 by adaly             #+#    #+#             */
/*   Updated: 2017/01/21 02:20:24 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	int return_value;

	return_value = 0;
	if (c >= 'A' && c <= 'Z')
		return_value = 1;
	if (c >= 'a' && c <= 'z')
		return_value = 1;
	return (return_value);
}
