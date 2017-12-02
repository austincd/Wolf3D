/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 13:01:14 by adaly             #+#    #+#             */
/*   Updated: 2017/05/18 15:30:27 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_open_file(char *file_path)
{
	int	file_descriptor;

	file_descriptor = 0;
	if (*file_path)
		file_descriptor = open(file_path, O_RDONLY);
	return (file_descriptor);
}
