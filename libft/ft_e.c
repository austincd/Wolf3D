/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_e.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 19:03:05 by adaly             #+#    #+#             */
/*   Updated: 2017/06/05 20:02:49 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		**ft_e_helper1(void)
{
	char	**strings;

	strings = NULL;
	strings = (char**)ft_memalloc(sizeof(char*) * 3);
	strings[0] = NULL;
	strings[1] = NULL;
	strings[2] = NULL;
	return (strings);
}

static int		ft_e_helper2(long double *num, char **str)
{
	int counter;
	int sign;

	*str = NULL;
	counter = 0;
	sign = 0;
	if (*num < 0)
	{
		sign = -1;
		*num *= -1;
	}
	while (*num >= 10)
	{
		*num /= 10;
		++counter;
	}
	if (sign == -1)
	{
		*str = ft_strdup("-");
		ft_restrcat(str, ft_ftoa(*num));
	}
	else
		*str = ft_ftoa(*num);
	return (counter);
}

void			ft_e(t_pfconv *current, long double num)
{
	int		counter;
	char	**strings;

	strings = ft_e_helper1();
	counter = ft_e_helper2(&num, strings);
	strings[1] = ft_strdup("E+");
	strings[2] = ft_itoa(counter);
	if (counter < 10)
		ft_restrcat(strings + 1, "0");
	ft_restrcat(strings + 1, strings[2]);
	current->string = strings[0];
	current->exponent = strings[1];
	if (strings[2])
		ft_strdel_plus(strings + 2);
	if (current->type == 'e')
	{
		ft_strlowcase(current->exponent);
		ft_strlowcase(current->string);
	}
	free(strings);
}
