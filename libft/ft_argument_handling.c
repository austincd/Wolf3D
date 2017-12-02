/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument_handling.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 19:34:56 by adaly             #+#    #+#             */
/*   Updated: 2017/06/10 21:04:02 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_pfconv	*ft_conversion_parsing(char **str)
{
	t_pfconv	*new;
	char		*temp;
	char		**types;

	types = ft_build_types();
	new = ft_new_pfconv();
	if (str && new)
	{
		if (**str == '%')
		{
			temp = *str;
			*str = *str + 1;
			*str = ft_parse_parameter(*str, new);
			*str = ft_parse_flags(*str, new);
			*str = ft_parse_width(*str, new);
			*str = ft_parse_precision(*str, new);
			*str = ft_parse_length(*str, new, ft_build_lengths());
			*str = ft_parse_type(*str, new, types);
			if (new->type == 'o')
				new->base = 8;
			new->conv_length = *str - temp;
		}
	}
	ft_free_types(types);
	return (new);
}

char		*ft_parse_parameter(char *str, t_pfconv *new)
{
	char *ptr;

	ptr = str;
	if (new)
		new->parameter = -1;
	if (ptr)
	{
		while (ft_isdigit(*ptr))
			++ptr;
		if (*ptr == '$')
		{
			new->parameter = ft_atoi(str);
			return (ptr + 1);
		}
	}
	return (str);
}

char		*ft_parse_flags(char *str, t_pfconv *new)
{
	char	*ptr;
	char	*flags;
	int		index;

	index = 0;
	flags = ft_strdup("-+ 0#");
	ptr = str;
	if (new)
	{
		new->flags = (int*)ft_memalloc(sizeof(int) * 5);
		if (ptr && new->flags)
		{
			while (ft_strchr(flags, *ptr))
			{
				index = ft_strchr(flags, *ptr) - flags;
				new->flags[index] = 1;
				++ptr;
			}
			ft_strdel_plus(&flags);
			return (ptr);
		}
	}
	ft_strdel_plus(&flags);
	return (str);
}

char		*ft_parse_width(char *ptr, t_pfconv *new)
{
	new->width = 0;
	if (ptr)
	{
		if (*ptr == '*')
		{
			new->width = -2;
			return (ptr + 1);
		}
		else if (ft_isdigit(*ptr))
		{
			new->width = ft_atoi(ptr);
			while (ft_isdigit(*ptr))
				++ptr;
			if (*ptr == '*')
			{
				new->width = -2;
				return (ptr + 1);
			}
			return (ptr);
		}
		else
			return (ptr);
	}
	return (ptr);
}

char		*ft_parse_precision(char *ptr, t_pfconv *new)
{
	if (new)
	{
		if (ptr)
		{
			if (*ptr == '.')
			{
				++ptr;
				if (ft_isdigit(*ptr))
				{
					new->precision = ft_atoi(ptr);
					while (ft_isdigit(*ptr))
						++ptr;
				}
				else if (*ptr == '*')
				{
					new->precision = -2;
					++ptr;
				}
				else
					new->precision = 0;
			}
		}
	}
	return (ptr);
}
