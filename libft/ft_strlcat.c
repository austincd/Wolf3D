/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 18:59:58 by adaly             #+#    #+#             */
/*   Updated: 2017/01/21 02:03:42 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*append_point;
	size_t	init_dst_length;
	size_t	src_length;

	src_length = (size_t)ft_strlen((char*)src);
	init_dst_length = (size_t)ft_strlen(dst);
	append_point = dst + init_dst_length;
	if (size > init_dst_length)
		ft_strlcpy(append_point, src, (size - init_dst_length));
	if (size < init_dst_length)
		init_dst_length = size;
	return (init_dst_length + src_length);
}
