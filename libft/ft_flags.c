/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 21:34:57 by adaly             #+#    #+#             */
/*   Updated: 2017/06/10 20:24:53 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_hash(t_pfconv *current)
{
	if (current->flags[4] == 1)
	{
		if (ft_lowercase(current->type) == 'o' && current->string[0] != '0')
			ft_restrcat(&(current->prefix), "0");
		if (current->type == 'x' && ft_atoi(current->string))
			ft_restrcat(&(current->prefix), "0x");
		if (current->type == 'X' && ft_atoi(current->string))
			ft_restrcat(&(current->prefix), "0X");
		if (current->widthstr)
			current->widthstr[ft_strlen(current->widthstr) - \
			ft_strlen(current->prefix)] = 0;
	}
}

void		ft_space(t_pfconv *current)
{
	char *ints;

	ints = ft_strdup("idID");
	if (current)
	{
		if (!current->flags[1] && current->flags[2] && \
		ft_strchr(ints, current->type))
		{
			if (!ft_strchr(current->string, '-') && !current->widthstr)
			{
				current->widthstr = ft_strdup(" ");
				current->chars += 1;
			}
			else if (!ft_strchr(current->string, '-') && current->widthstr)
				current->widthstr[0] = ' ';
		}
	}
	ft_strdel_plus(&ints);
}

static void	ft_plus_helper(t_pfconv *current, char **temp)
{
	if (current->flags[0])
	{
		*temp = ft_strjoin("+", current->string);
		ft_strdel_plus(&(current->string));
		current->string = *temp;
		current->widthstr[ft_strlen(current->widthstr) - 1] = 0;
	}
	else
	{
		*temp = ft_strdup("+");
		ft_restrcat(temp, current->prefix);
		ft_strdel_plus(&(current->prefix));
		current->prefix = *temp;
	}
}

void		ft_plus(t_pfconv *current)
{
	char	*ints;
	char	*temp;

	ints = ft_strdup("idID");
	if (current)
	{
		if (current->flags[1] && ft_strchr(ints, current->type) && \
		!ft_strchr(current->string, '-'))
		{
			if (current->widthstr && !current->flags[0])
			{
				if (current->flags[3])
					current->widthstr[0] = '+';
				else
					current->widthstr[ft_strlen(current->widthstr) - 1] = '+';
			}
			else
				ft_plus_helper(current, &temp);
		}
	}
	ft_strdel_plus(&ints);
}

void		ft_zero(t_pfconv *current)
{
	char *ints;

	ints = ft_strdup("xuidoODXUI");
	if (current)
	{
		if (current->flags[3] && ft_strchr(ints, current->type) && \
		current->widthstr && !current->flags[0])
		{
			ft_memset(current->widthstr, '0', \
			ft_strlen(current->widthstr));
			if (current->precision < current->width && current->precision > 0)
			{
				if (ft_strchr(current->string, '-'))
					ft_memset(current->widthstr, ' ', \
					(current->width - (current->precision + 1)));
				else
					ft_memset(current->widthstr, ' ', \
					current->width - current->precision);
			}
		}
	}
	ft_strdel_plus(&ints);
}
