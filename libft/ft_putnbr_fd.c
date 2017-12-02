/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 05:08:18 by adaly             #+#    #+#             */
/*   Updated: 2017/01/21 03:02:54 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long internal;

	internal = (long long)n;
	if (internal < 0)
	{
		ft_putchar_fd('-', fd);
		internal *= -1;
	}
	if (internal <= 9)
		ft_putchar_fd((int)internal + 48, fd);
	if (internal > 9)
	{
		ft_putnbr_fd((int)(internal / 10), fd);
		ft_putnbr_fd((int)(internal % 10), fd);
	}
}
