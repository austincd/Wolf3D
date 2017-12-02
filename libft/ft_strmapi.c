/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 20:04:30 by adaly             #+#    #+#             */
/*   Updated: 2017/01/21 02:41:55 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
				new_str[which_int] = f(which_int, s[which_int]);
				which_int++;
			}
			new_str[which_int] = '\0';
		}
	}
	return (new_str);
}
