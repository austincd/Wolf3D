/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 04:32:43 by adaly             #+#    #+#             */
/*   Updated: 2017/01/21 02:52:17 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(unsigned int c, int fd)
{
	int				char_length;
	unsigned char	*ptr;

	ptr = ((unsigned char*)&c);
	char_length = ft_utf8width(ptr);
	write(fd, ptr, char_length);
}
