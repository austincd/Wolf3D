/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_restrinsert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 16:02:33 by adaly             #+#    #+#             */
/*   Updated: 2017/06/10 16:15:05 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_restrinsert(char **str, char *insert, uintmax_t spot)
{
	char		*new;
	uintmax_t	new_size;

	new_size = 0;
	new = NULL;
	if (str)
	{
		new_size += ft_strlen(*str);
		new_size += ft_strlen(insert);
		new = ft_strnew(new_size);
		if (new)
		{
			ft_strncat(new, *str, spot);
			ft_strcat(new, insert);
			ft_strcat(new, *str + spot);
			ft_strdel_plus(str);
			*str = new;
		}
	}
}

void	ft_rewstrinsert(wchar_t **wstr, wchar_t *insert, uintmax_t spot)
{
	wchar_t		*wnew;
	uintmax_t	new_size;

	new_size = 0;
	new = NULL;
	if (str)
	{
		new_size += ft_wstrlen(*str);
		new_size += ft_wstrlen(insert);
		new = ft_wstrnew(new_size);
		if (new)
		{
			ft_wstrncat(new, *wstr, spot);
			ft_wstrcat(new, insert);
			ft_wstrcat(new, *wstr + spot);
			ft_wstrdel_plus(str);
			*wstr = new;
		}
	}
}
