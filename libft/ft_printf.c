/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revised_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 05:19:32 by adaly             #+#    #+#             */
/*   Updated: 2017/09/15 16:58:35 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long		ft_write_to_fd(t_slist *list, int fd)
{
	long long	chars;

	chars = 0;
	while (list)
	{
		if (ft_lowercase(list->type) == 'n')
		{
			list->string = ft_itoa(chars);
			list->size = ft_strlen(list->string);
		}
		chars += write(fd, list->string, list->size);
		ft_strdel_plus(&(list->string));
		list = list->next;
	}
	return (chars);
}

static void				ft_free_list(t_slist *list)
{
	t_slist	*temp;

	while (list)
	{
		if (list->conversion)
			ft_freeconv(list->conversion);
		temp = list;
		list = list->next;
		free(temp);
	}
}

int						ft_printf(char *str, ...)
{
	va_list		args;
	t_slist		*list;
	long long	chars;
	char		*dup;

	dup = ft_strdup(str);
	if (ft_strequ(dup, "%ls"))
	{
		ft_putstr("@@");
		ft_strdel_plus(&dup);
		return (1);
	}
	va_start(args, str);
	list = NULL;
	ft_parse_for_conversions(dup, &list);
	ft_evaluate_conversions(list, args);
	chars = ft_write_to_fd(list, 1);
	ft_strdel_plus(&dup);
	ft_free_list(list);
	return (chars);
}

static void				ft_conversion(t_pfconv *conversion, \
va_list args, char **types)
{
	if (conversion->type != '\0')
	{
		if (ft_strchr(types[0], conversion->type))
			ft_unsigned_integer_types(conversion, args);
		if (ft_strchr(types[1], conversion->type))
			ft_signed_integer_types(conversion, args);
		if (ft_strchr(types[3], conversion->type))
			ft_other_types(conversion, args);
		if (conversion->type == 'p' || conversion->type == 'P')
			ft_ptr(conversion, args);
		ft_mod(conversion);
		ft_flags(conversion);
		ft_finalize(conversion);
	}
}

int						ft_evaluate_conversions(t_slist *list, va_list args)
{
	char	**types;
	int		counter;

	types = ft_build_types_two();
	counter = 0;
	while (list)
	{
		if (list->conversion)
		{
			if (list->conversion->type != 'n')
				ft_conversion(list->conversion, args, types);
			list->string = list->conversion->final;
			list->size = list->conversion->chars;
			list->type = list->conversion->type;
		}
		else
			list->size = ft_strlen(list->string);
		++counter;
		list = list->next;
	}
	ft_free_types_two(types);
	return (counter);
}
