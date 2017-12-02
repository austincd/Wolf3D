/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floating_types.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 14:21:01 by adaly             #+#    #+#             */
/*   Updated: 2017/06/08 02:18:31 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_g(t_pfconv *current, long double num)
{
	unsigned long long	length1;
	unsigned long long	length2;
	char				*temp;
	char				*temp2;

	ft_e(current, num);
	temp = ft_float_normal(current, num, 10);
	temp2 = ft_strstr(current->string, "0000");
	if (temp2)
		*temp2 = 0;
	length2 = ft_strlen(temp);
	length1 = ft_strlen(current->string);
	if (length1 + ft_strlen(current->exponent) < length2 || length2 > 6)
	{
		current->precision = 5;
		ft_strdel_plus(&temp);
	}
	else
	{
		ft_strdel_plus(&(current->string));
		current->string = temp;
		ft_strdel_plus(&(current->exponent));
	}
	if (current->type == 'g' && current->exponent)
		ft_strlowcase(current->exponent);
}

static void		ft_a_helper(long double *div, long double *num, \
char **str, int *counter)
{
	*counter = -7;
	*str = NULL;
	if (*num < 0)
	{
		*num *= -1;
		*str = ft_strdup("-0X");
	}
	else if (*num == 0)
		*str = ft_strdup("0X0");
	else
		*str = ft_strdup("0X");
	*div = *num;
	while (*div >= 2)
		*div = *num / ft_power(++(*counter), 2);
}

static void		ft_a(t_pfconv *current, long double num)
{
	int			counter;
	char		*str;
	char		*last;
	long double div;

	ft_a_helper(&div, &num, &str, &counter);
	last = ft_basefloat(div, 16);
	ft_restrcat(&str, last);
	ft_strdel_plus(&last);
	current->exponent = ft_strdup("P");
	if (div == 0)
		counter = 0;
	if (counter >= 0)
		ft_restrcat(&current->exponent, "+");
	last = ft_itoa(counter);
	ft_restrcat(&current->exponent, last);
	ft_strdel_plus(&last);
	if (current->type == 'a')
	{
		ft_strlowcase(str);
		ft_strlowcase(current->exponent);
	}
	current->string = str;
}

void			ft_floating_types(t_pfconv *current, va_list args)
{
	long double	new;

	ft_import_options(current, args);
	if (current->precision <= 0 && ft_lowercase(current->type) != 'a' \
	&& ft_lowercase(current->type) != 'g')
		current->precision = 6;
	if (current->length == 4)
		new = va_arg(args, long double);
	else
		new = va_arg(args, double);
	if (ft_lowercase(current->type) == 'g')
		ft_g(current, new);
	else if (ft_lowercase(current->type) == 'e')
		ft_e(current, new);
	else if (ft_lowercase(current->type) == 'f')
		current->string = ft_float_normal(current, new, 10);
	else if (ft_lowercase(current->type) == 'a')
		ft_a(current, new);
	current->chars = ft_strlen(current->string);
}
