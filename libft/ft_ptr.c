/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 13:16:18 by adaly             #+#    #+#             */
/*   Updated: 2017/06/08 02:50:39 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_ptr(t_pfconv *current, va_list args)
{
	void	*ptr;
	char	*temp;

	ptr = NULL;
	temp = NULL;
	if (current && args)
	{
		ft_import_options(current, args);
		ptr = va_arg(args, void*);
		temp = ft_utoa_base((unsigned long long)ptr, 16);
		current->string = ft_strlowcase(ft_strjoin("0x", temp));
		if (temp)
			free(temp);
		current->chars = ft_strlen(current->string);
	}
	return (ft_strlen(current->string));
}
