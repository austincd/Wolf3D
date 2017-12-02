/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 18:27:39 by adaly             #+#    #+#             */
/*   Updated: 2017/01/21 06:12:42 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_numeric(char *str)
{
	int return_value;
	int cur_char;

	cur_char = 0;
	while (str[cur_char] >= '0' && str[cur_char] <= '9')
		cur_char++;
	if (str[cur_char] == '\0')
		return_value = 1;
	else
		return_value = 0;
	return (return_value);
}
