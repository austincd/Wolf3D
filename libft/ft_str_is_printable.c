/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 18:52:49 by adaly             #+#    #+#             */
/*   Updated: 2017/01/21 06:12:13 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_printable(char *str)
{
	int return_value;
	int cur_char;

	cur_char = 0;
	while (str[cur_char] >= ' ' && str[cur_char] != 127)
		cur_char++;
	if (str[cur_char] == '\0')
		return_value = 1;
	else
		return_value = 0;
	return (return_value);
}
