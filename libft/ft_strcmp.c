/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 09:51:21 by adaly             #+#    #+#             */
/*   Updated: 2017/01/21 02:11:14 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	void	*alpha;
	void	*beta;
	size_t	str_len;
	int		result;

	alpha = (void*)s1;
	beta = (void*)s2;
	str_len = ft_strlen(alpha);
	if (ft_strlen(beta) > str_len)
		str_len = ft_strlen(beta);
	result = ft_memcmp(alpha, beta, (str_len + 1));
	return (result);
}
