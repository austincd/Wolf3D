/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 18:35:32 by adaly             #+#    #+#             */
/*   Updated: 2017/01/21 06:12:23 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_lowercase(char *str)
{
	int return_value;
	int cur_char;

	cur_char = 0;
	while (str[cur_char] >= 'a' && str[cur_char] <= 'z')
		cur_char++;
	if (str[cur_char] == '\0')
		return_value = 1;
	else
		return_value = 0;
	return (return_value);
}
