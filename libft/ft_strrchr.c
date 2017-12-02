/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 17:51:02 by adaly             #+#    #+#             */
/*   Updated: 2017/01/21 02:01:25 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	void *ptr;
	char *result;

	ptr = (void*)s;
	result = ft_memrchr(ptr, c, (ft_strlen(ptr) + 1));
	return (result);
}
