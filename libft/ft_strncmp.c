/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 09:51:21 by adaly             #+#    #+#             */
/*   Updated: 2017/01/21 02:23:21 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	void	*alpha;
	void	*beta;
	int		result;
	size_t	shorter_string;

	alpha = (void*)s1;
	beta = (void*)s2;
	shorter_string = n;
	if ((size_t)ft_strlen((char*)s1) < shorter_string)
		shorter_string = (size_t)ft_strlen((char*)s1) + 1;
	if ((size_t)ft_strlen((char*)s2) < shorter_string)
		shorter_string = (size_t)ft_strlen((char*)s2) + 1;
	result = ft_memcmp(alpha, beta, shorter_string);
	return (result);
}
