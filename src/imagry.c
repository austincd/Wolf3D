/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imagry.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 00:24:42 by adaly             #+#    #+#             */
/*   Updated: 2017/10/13 17:00:32 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void		display_info(t_env *env)
{
	char	str[72];

	if (env)
	{
		ft_bzero(str, 72);
		ft_strcat(str, "Palette: ");
		ft_strcat(str, env->colors[env->ei].name);
		mlx_string_put(env->mlx, env->p, 5, WS - 30, WHITE, str);
	}
}

void		image_forget(t_env *env)
{
	intmax_t	num_bytes;

	num_bytes = -1;
	if (env && env->pix)
	{
		num_bytes = env->bnum * WS;
		if (num_bytes > 0)
			ft_bzero(env->pix, num_bytes);
	}
}
