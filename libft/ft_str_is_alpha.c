/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 17:55:26 by adaly             #+#    #+#             */
/*   Updated: 2017/01/21 06:12:33 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_alpha(char *str)
{
	int return_value;
	int cur_char;

	cur_char = 0;
	while ((str[cur_char] >= 'a' && str[cur_char] <= 'z') || \
			(str[cur_char] >= 'A' && str[cur_char] <= 'Z'))
		cur_char++;
	if (str[cur_char] == '\0')
		return_value = 1;
	else
		return_value = 0;
	return (return_value);
}
