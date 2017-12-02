/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isthere_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 05:44:16 by adaly             #+#    #+#             */
/*   Updated: 2017/01/21 06:11:57 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isthere_var(char *str, char var, int (*f)(char, char), int n)
{
	int counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		if (f(str[counter], var) == n)
			return (1);
		counter++;
	}
	return (0);
}
