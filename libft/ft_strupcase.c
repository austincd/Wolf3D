/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 10:18:45 by adaly             #+#    #+#             */
/*   Updated: 2017/01/21 06:13:45 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int str_place;

	str_place = 0;
	while (str[str_place] != '\0')
	{
		if (str[str_place] > 96 && str[str_place] < 123)
			str[str_place] -= 32;
		str_place++;
	}
	return (str);
}
