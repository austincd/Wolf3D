/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 18:25:54 by adaly             #+#    #+#             */
/*   Updated: 2017/04/26 18:33:23 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *str, long long len)
{
	char		*new;

	new = NULL;
	new = ft_strnew(len);
	if (new)
		ft_strlcpy(new, str, len + 1);
	return (new);
}
