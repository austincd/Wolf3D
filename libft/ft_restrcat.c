/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_restrcat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 11:30:29 by adaly             #+#    #+#             */
/*   Updated: 2017/05/18 15:31:20 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_restrcat(char **dst, char *src)
{
	char *tmp;

	tmp = *dst;
	if (*dst && src)
	{
		*dst = ft_strjoin(*dst, src);
		free(tmp);
	}
	else if (src)
	{
		*dst = ft_strdup(src);
		free(tmp);
	}
	return (*dst);
}
