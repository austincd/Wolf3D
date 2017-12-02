/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_restrccat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 11:33:23 by adaly             #+#    #+#             */
/*   Updated: 2017/05/18 14:58:23 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_restrccat(char **dst, char *src, char c)
{
	char *found;
	char *tmp;

	found = NULL;
	if (!(found = ft_strchr(src, c)))
	{
		ft_restrcat(dst, src);
	}
	else
	{
		tmp = ft_strsub(src, 0, (found - src));
		ft_restrcat(dst, tmp);
	}
	return (*dst);
}
