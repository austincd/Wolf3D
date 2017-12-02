/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manuever.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:26:54 by adaly             #+#    #+#             */
/*   Updated: 2017/11/24 15:03:24 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void	ft_dirToCam(t_w3d *mother)
{
	if (mother)
	{
		mother->p1.actor.obj.dirY = mother->p1.cam.dirY;
		mother->p1.actor.obj.dirX = mother->p1.cam.dirX;
	}
}

void	ft_fadeRight(t_w3d *mother)
{
	long double	temp;

	if (mother && !mother->p1.actor.active)
	{
		ft_dirToCam(mother);
		temp = mother->p1.actor.obj.dirY;
		mother->p1.actor.obj.dirY = mother->p1.actor.obj.dirX * -1;
		mother->p1.actor.obj.dirX = temp * -1;
		mother->p1.actor.obj.velo = mother->p1.actor.agility * 5;
		mother->p1.actor.active = 0.5;
		mother->p1.actor.invul = 0.3;
		mother->keys.fadeLeft = 0;
	}
}

void	ft_fadeLeft(t_w3d *mother)
{
	long double	temp;

	if (mother && !mother->p1.actor.active)
	{
		ft_dirToCam(mother);
		temp = mother->p1.actor.obj.dirY;
		mother->p1.actor.obj.dirY = mother->p1.actor.obj.dirX;
		mother->p1.actor.obj.dirX = temp;
		mother->p1.actor.obj.velo = mother->p1.actor.agility * 5;
		mother->p1.actor.active = 0.5;
		mother->p1.actor.invul = 0.3;
		mother->keys.fadeLeft = 0;
	}
}
