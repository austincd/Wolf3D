/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf8width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 08:54:45 by adaly             #+#    #+#             */
/*   Updated: 2017/01/21 03:10:45 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_utf8width(unsigned char *s)
{
	int char_length;

	char_length = 1;
	if (*s >= 192)
		char_length = 2;
	if (*s >= 224)
		char_length = 3;
	if (*s >= 240)
		char_length = 4;
	return (char_length);
}
