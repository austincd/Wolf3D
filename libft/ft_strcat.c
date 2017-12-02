/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 18:59:58 by adaly             #+#    #+#             */
/*   Updated: 2017/01/21 02:23:06 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	char *append_point;
	char *s2_char;

	s2_char = (char*)s2;
	append_point = s1 + ft_strlen(s1);
	ft_strcpy(append_point, s2_char);
	return (s1);
}
