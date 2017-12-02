/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 04:38:29 by adaly             #+#    #+#             */
/*   Updated: 2017/01/21 03:08:50 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int loc_str;
	int *ptr;

	if (s)
	{
		loc_str = 0;
		while (s[loc_str] != '\0')
		{
			ptr = (int*)&s[loc_str];
			ft_putchar_fd(*ptr, fd);
			loc_str += ft_utf8width((unsigned char*)(&(s[loc_str])));
		}
	}
}
