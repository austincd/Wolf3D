/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_types.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 20:12:55 by adaly             #+#    #+#             */
/*   Updated: 2017/06/10 20:02:19 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_char(t_pfconv *current, char c)
{
	current->string = ft_strnew(1);
	current->string[0] = c;
	current->chars = 1;
	return (1);
}

static int	ft_string(t_pfconv *current, char *c)
{
	if (c)
	{
		current->string = ft_strdup(c);
		current->chars = ft_strlen(current->string);
	}
	else
	{
		current->string = ft_strdup("(null)");
		current->chars = ft_strlen(current->string);
	}
	return (current->chars);
}

int			ft_other_types(t_pfconv *current, va_list args)
{
	ft_import_options(current, args);
	if (ft_lowercase(current->type) == 'c')
		ft_char(current, va_arg(args, int));
	if (ft_lowercase(current->type) == 's')
		ft_string(current, va_arg(args, char*));
	if (current->type == '%')
		ft_char(current, '%');
	return (current->chars);
}
