/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 05:03:11 by adaly             #+#    #+#             */
/*   Updated: 2017/06/12 19:14:49 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_float_standard(t_pfconv *current, long double num, int base)
{
	int		exponent;
	char	*new;
	char	*exp;
	char	*temp;

	exponent = 0;
	while (num >= base)
	{
		num /= base;
		++exponent;
	}
	temp = ft_itoa_base(exponent, base);
	if ((int)ft_strlen(temp) < base)
		exp = ft_strjoin("0", temp);
	else
		exp = temp;
	new = ft_itoa_float(num, base);
	ft_restrcat(&new, "e");
	if (current->capitalized)
		new[ft_strlen(new) - 1] = 'E';
	ft_restrcat(&new, exp);
	if (temp != exp)
		ft_strdel_plus(&temp);
	ft_strdel_plus(&exp);
	return (new);
}

static void	ft_float_normal_helper(t_pfconv *current, char ***ptrs, \
long double num, int base)
{
	char	**new;
	char	**prefix;
	char	**temp;

	new = ptrs[2];
	prefix = ptrs[0];
	temp = ptrs[1];
	*prefix = ft_strdup("0x");
	if (current->capitalized)
		(*prefix)[1] = 'X';
	if (base == 16)
	{
		*temp = ft_itoa_float(num, base);
		*new = ft_strjoin(*prefix, *temp);
		ft_strdel_plus(temp);
	}
	else
		*new = ft_itoa_float(num, base);
}

char		*ft_float_normal(t_pfconv *current, long double num, int base)
{
	char	*new;
	char	*prefix;
	char	*temp;
	char	**ptrs[3];

	ptrs[0] = &prefix;
	ptrs[1] = &temp;
	ptrs[2] = &new;
	ft_float_normal_helper(current, ptrs, num, base);
	if (ft_lowercase(current->type) == 'g')
	{
		temp = ft_strrchr(new, '0');
		if (temp)
		{
			while (*temp == '0')
				--temp;
			if (*temp == '.')
				*temp = 0;
			else
				temp[1] = 0;
		}
	}
	ft_strdel_plus(&prefix);
	return (new);
}

char		**ft_float_build_invalids(int capitalized)
{
	char **new;

	new = NULL;
	new = (char**)ft_memalloc(sizeof(char*) * 3);
	if (new)
	{
		if (capitalized)
		{
			new[0] = ft_strdup("INF");
			new[1] = ft_strdup("INFINITY");
			new[2] = ft_strdup("NAN");
		}
		else
		{
			new[0] = ft_strdup("inf");
			new[1] = ft_strdup("infinity");
			new[2] = ft_strdup("nan");
		}
	}
	return (new);
}
