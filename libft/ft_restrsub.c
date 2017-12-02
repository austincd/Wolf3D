/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_restrsub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:53:35 by adaly             #+#    #+#             */
/*   Updated: 2017/05/18 14:58:47 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_restrsub(char **str, char *strtwo, unsigned int start, size_t len)
{
	char *tmp;

	tmp = *str;
	*str = ft_strsub(strtwo, start, len);
	ft_strclr(tmp);
	free(tmp);
	return (*str);
}
