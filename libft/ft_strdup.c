/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 23:56:57 by adaly             #+#    #+#             */
/*   Updated: 2017/01/21 02:12:21 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		s1_size;
	int		which_char;
	char	*duplicate;

	s1_size = ft_strlen((char*)s1) + 1;
	which_char = 0;
	duplicate = (char*)malloc(s1_size);
	while (s1[which_char] != '\0' && duplicate != NULL)
	{
		duplicate[which_char] = s1[which_char];
		which_char++;
	}
	if (duplicate != NULL)
		duplicate[which_char] = '\0';
	return (duplicate);
}
