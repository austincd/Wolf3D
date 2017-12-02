/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 19:17:31 by adaly             #+#    #+#             */
/*   Updated: 2017/06/12 17:52:14 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_parse_length(char *str, t_pfconv *new, char **options)
{
	char	*ptr;
	int		counter;

	counter = 0;
	ptr = str;
	if (new)
	{
		new->length = -1;
		if (ptr)
		{
			new->length = ft_strequ_multi(ptr, options, 8);
			if (new->length >= 0)
				ptr += ft_strlen(options[new->length]);
		}
	}
	ft_free_lengths(options);
	return (ptr);
}

char		*ft_parse_type(char *str, t_pfconv *new, char **types)
{
	char	*ptr;

	ptr = str;
	if (new && types)
	{
		new->type = '%';
		if (ptr)
		{
			while (!ft_strchr(types[0], *ptr) && *ptr)
				++ptr;
			if (ft_strchr(types[0], *ptr))
			{
				new->type = *ptr;
				if (new->type == 'a' || new->type == 'x')
					new->base = 16;
				if (new->type != *ptr)
					new->capitalized = 1;
				if (ft_strchr(types[5], *ptr))
					new->length = 2;
				return (ptr + 1);
			}
		}
	}
	return (NULL);
}

char		**ft_build_lengths(void)
{
	char **lengths;

	lengths = (char**)ft_memalloc(sizeof(char*) * 8);
	lengths[0] = ft_strdup("hh");
	lengths[1] = ft_strdup("h");
	lengths[2] = ft_strdup("l");
	lengths[3] = ft_strdup("ll");
	lengths[4] = ft_strdup("L");
	lengths[5] = ft_strdup("z");
	lengths[6] = ft_strdup("j");
	lengths[7] = ft_strdup("t");
	return (lengths);
}

t_pfconv	*ft_new_pfconv(void)
{
	t_pfconv	*new;

	new = NULL;
	new = (t_pfconv*)ft_memalloc(sizeof(t_pfconv));
	if (new)
	{
		new->base = 10;
		new->length = 0;
		new->precision = -1;
		new->width = -1;
		new->capitalized = 0;
		new->type = 0;
		new->import_type = 0;
		new->conv_length = 0;
		new->parameter = 0;
		new->flags = NULL;
		new->string = NULL;
	}
	return (new);
}
