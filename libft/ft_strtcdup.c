/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strctdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 18:33:39 by adaly             #+#    #+#             */
/*   Updated: 2017/05/18 15:00:01 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtcdup(char *str, char c)
{
	char		*new;
	long long	size;

	new = NULL;
	size = 0;
	if (ft_strchr(str, c))
	{
		size = ft_strchr(str, c) - str;
		new = ft_strndup(str, size);
	}
	else
	{
		new = ft_strdup(str);
	}
	return (new);
}
