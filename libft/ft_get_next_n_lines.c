/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_n_lines.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 15:43:00 by adaly             #+#    #+#             */
/*   Updated: 2017/04/27 17:40:43 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

int		ft_get_next_n_lines(int fd, int n, char **lines)
{
	char	*temp1;
	char	*temp2;
	int		counter;
	int		status;

	counter = 0;
	status = 0;
	temp2 = ft_strdup("");
	while (counter < n && (status = get_next_line(fd, &temp1)))
	{
		ft_restrcat(&temp2, "\n");
		ft_restrcat(&temp2, temp1);
		++counter;
	}
	if (counter == n)
	{
		*lines = temp2;
		return (1);
	}
	return (-1);
}
