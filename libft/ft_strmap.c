/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 20:04:30 by adaly             #+#    #+#             */
/*   Updated: 2017/01/21 03:09:54 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	which_int;
	unsigned int	string_size;
	char			*new_str;

	new_str = NULL;
	if (s && f)
	{
		string_size = (unsigned int)ft_strlen((char*)s) + 1;
		new_str = (char*)malloc(sizeof(char) * string_size);
		if (new_str)
		{
			which_int = 0;
			while (s[which_int] != '\0')
			{
				new_str[which_int] = f(s[which_int]);
				which_int++;
			}
			new_str[which_int] = '\0';
		}
	}
	return (new_str);
}
