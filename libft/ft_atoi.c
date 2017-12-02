/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 05:31:13 by adaly             #+#    #+#             */
/*   Updated: 2017/09/15 17:24:46 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sign(char *str)
{
	int sign;

	sign = 0;
	if (str[0] == '-')
		sign = -1;
	if (str[0] == '+')
		sign = 1;
	return (sign);
}

static int	ft_power_of_ten(int power)
{
	int nb;

	nb = 1;
	while (power > 1)
	{
		nb *= 10;
		power--;
	}
	return (nb);
}

static int	ft_trim_whitespace(char *str)
{
	int wspace_chars;

	wspace_chars = 0;
	while ((str[wspace_chars] >= 9 && str[wspace_chars] <= 13)		 \
			|| (str[wspace_chars] == 32))
	{
		wspace_chars++;
	}
	return (wspace_chars);
}

int			ft_atoi(char *str)
{
	int			digit;
	int			str_place;
	long long	result;
	int			num_of_digits;
	int			sign;

	str_place = ft_trim_whitespace(str);
	sign = ft_sign(&str[str_place]);
	result = 0;
	num_of_digits = str_place;
	sign != 0 ? str_place++ : str_place + 0;
	sign != 0 ? num_of_digits++ : num_of_digits + 0;
	while (str[num_of_digits] > 47 && str[num_of_digits] < 58)
		num_of_digits++;
	while (str_place < num_of_digits)
	{
		digit = (*(str + str_place)) - 48;
		result += (digit * ft_power_of_ten(num_of_digits - str_place));
		str_place++;
	}
	if (sign == -1)
		result *= -1;
	return ((int)result);
}
