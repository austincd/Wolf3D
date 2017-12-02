/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 06:58:44 by adaly             #+#    #+#             */
/*   Updated: 2017/01/21 02:42:46 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_numlen(int num)
{
	long long	num_in;
	int			digits;

	digits = 0;
	num_in = num;
	if (num_in <= 0)
		digits = 1;
	while (num_in != 0)
	{
		num_in /= 10;
		digits++;
	}
	return (digits);
}
