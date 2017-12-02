/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 21:16:19 by adaly             #+#    #+#             */
/*   Updated: 2017/11/10 01:05:16 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void	ft_expire(t_w3d *mother, long double *value)
{
	if (mother && value)
	{
		if (*value <= ((double)mother->tickLength / 1000000))
			*value = 0;
		else
			*value -= ((double)mother->tickLength / 1000000);
	}
}

void	ft_decay(t_w3d *mother)
{
	int	counter;

	counter = 0;
	if (mother)
	{
		ft_expire(mother, &(mother->p1.actor.active));
		ft_expire(mother, &(mother->p1.actor.invul));
		ft_expire(mother, &(mother->p1.bonusDuration));
		ft_expire(mother, &(mother->p1.techUpWindow));
		ft_expire(mother, &(mother->p1.techDownWindow));
		if (!(mother->p1.bonusDuration))
			mother->p1.bonus = 1.00;
		while (counter < LIMIT_ACTORS)
		{
			ft_expire(mother, &(mother->actors[counter].active));
			ft_expire(mother, &(mother->actors[counter].invul));
			++counter;
		}
	}
}

void	ft_timing(t_w3d *mother)
{
	long double	temp;

	temp = 1.0000;
	if (mother)
	{
		temp /= mother->tickRate;
		mother->tickLength = (int)(temp * 1000000);
	}
}
