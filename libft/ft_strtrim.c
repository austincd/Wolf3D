/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 20:25:36 by adaly             #+#    #+#             */
/*   Updated: 2017/01/21 06:08:42 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_iswhspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	else
		return (0);
}

static int		ft_isthere(char *str, int (*f)(char), int n)
{
	int counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		if (f(str[counter]) == n)
			return (1);
		counter++;
	}
	return (0);
}

char			*ft_strtrim(char const *s)
{
	int	which_char;

	which_char = 0;
	if (s)
	{
		while (ft_iswhspace((char)(*s)) == 1)
			s++;
		while (s[which_char] != '\0')
		{
			if (ft_iswhspace((char)s[which_char]) == 1)
			{
				if (ft_isthere(((char*)s + which_char), ft_iswhspace, 0) == 0)
					return (ft_strsub(s, 0, which_char));
			}
			which_char++;
		}
		return (ft_strsub(s, 0, which_char + 1));
	}
	else
		return (NULL);
}
