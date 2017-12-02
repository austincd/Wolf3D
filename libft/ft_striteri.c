/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 20:04:30 by adaly             #+#    #+#             */
/*   Updated: 2017/01/15 01:22:06 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int which_int;

	which_int = 0;
	if (s && f)
	{
		while (s[which_int] != '\0')
		{
			f(which_int, &(s[which_int]));
			which_int++;
		}
	}
}
