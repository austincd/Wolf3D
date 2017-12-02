/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 12:12:36 by adaly             #+#    #+#             */
/*   Updated: 2017/01/21 06:13:35 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int str_loc;
	int word_loc;

	str_loc = 0;
	word_loc = 0;
	while (str[str_loc] != '\0')
	{
		while ((str[str_loc] < 91 && str[str_loc] > 64) || \
			(str[str_loc] < 123 && str[str_loc] > 96) || \
			(str[str_loc] > 47 && str[str_loc] < 58))
		{
			if (word_loc == 0 && str[str_loc] > 96 && str[str_loc] < 123)
				str[str_loc] -= 32;
			if (word_loc > 0 && str[str_loc] > 64 && str[str_loc] < 91)
				str[str_loc] += 32;
			word_loc++;
			str_loc++;
		}
		word_loc = 0;
		str_loc++;
	}
	return (str);
}
