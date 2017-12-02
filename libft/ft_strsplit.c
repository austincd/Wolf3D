/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 16:10:24 by adaly             #+#    #+#             */
/*   Updated: 2017/01/21 06:09:28 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strsplit_helper(int *num, int *index, char ***str_array_ptr)
{
	*index = 0;
	*str_array_ptr = NULL;
	if (*num >= 0)
		*str_array_ptr = (char**)malloc(sizeof(char*) * (*num + 1));
}

char		**ft_strsplit(char const *s, char c)
{
	char	**split_array;
	char	*curstr;
	int		delim_str_len;
	int		num_strings;
	int		array_index;

	if (s && c > 0)
	{
		num_strings = ft_delimcount((char*)s, c);
		ft_strsplit_helper(&num_strings, &array_index, &split_array);
		if (split_array)
		{
			while (array_index < num_strings)
			{
				curstr = ft_delimcountto((char*)s, c, array_index + 1);
				delim_str_len = ft_delimstrlen(curstr, c);
				split_array[array_index] = ft_strsub(curstr, 0, delim_str_len);
				array_index++;
			}
			split_array[array_index] = NULL;
		}
		return (split_array);
	}
	return (NULL);
}
