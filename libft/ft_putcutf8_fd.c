/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcutf8_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 08:08:46 by adaly             #+#    #+#             */
/*   Updated: 2017/01/21 03:06:11 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putcutf8_fd(char *c, int fd)
{
	int char_length;

	char_length = ft_utf8width((unsigned char*)c);
	write(fd, c, char_length);
}
