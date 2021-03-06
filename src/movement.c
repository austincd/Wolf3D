/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:00:44 by adaly             #+#    #+#             */
/*   Updated: 2017/11/24 14:58:25 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void	ft_moveForward(t_w3d *mother, t_3di *ob3)
{
	if (mother && ob3)
	{
		if (mother->map.walls[(int)(ob3->posY)].col[(int)(ob3->posX + ob3->dirX * ob3->velo)] == '0')
			ob3->posX += ((ob3->dirX * ob3->velo));// * (mother->tickLength / 1000000));
		if (mother->map.walls[(int)(ob3->posY + ob3->dirY * ob3->velo)].col[(int)(ob3->posX)] == '0')
			ob3->posY += ((ob3->dirY * ob3->velo));// * (mother->tickLength / 1000000));
/*		if (mother->map.walls[(int)(ob3->posX + ob3->dirX * ob3->velo)].col[(int)(ob3->posY)] == '0')
			ob3->posX += ((ob3->dirX * ob3->velo));// * (mother->tickLength / 1000000));
		if (mother->map.walls[(int)(ob3->posX)].col[(int)(ob3->posY + ob3->dirY * ob3->velo)] == '0')
			ob3->posY += ((ob3->dirY * ob3->velo));// * (mother->tickLength / 1000000));*/
	}
}

void	ft_moveBackward(t_w3d *mother, t_3di *ob3)
{
	if (mother && ob3)
	{
		if (mother->map.walls[(int)(ob3->posX - ob3->dirX * ob3->velo)].col[(int)(ob3->posY)] == '0')
			ob3->posX += ((ob3->dirX * ob3->velo) * (mother->tickLength / 1000000));
		if (mother->map.walls[(int)(ob3->posX)].col[(int)(ob3->posY - ob3->dirY * ob3->velo)] == '0')
			ob3->posY += ((ob3->dirY * ob3->velo) * (mother->tickLength / 1000000));
	}
}

void	ft_obj_rot(t_w3d *mother, t_3di *obj)
{
	long double	oldDirX;
	long double	oldPlaneX;

	if (mother && obj)
	{
		oldDirX = obj->dirX;
		oldPlaneX = obj->planeX;
		obj->dirX = obj->dirX * cos(obj->rotVelo * (mother->tickLength / 10000)) - obj->dirY * sin(obj->rotVelo * (mother->tickLength / 10000));
		obj->dirY = oldDirX * sin(obj->rotVelo * (mother->tickLength / 10000)) + obj->dirY * cos(obj->rotVelo * (mother->tickLength / 10000));
		obj->planeX = obj->planeX * cos(obj->rotVelo * (mother->tickLength / 10000)) - obj->planeY * sin(obj->rotVelo * (mother->tickLength / 10000));
		obj->planeY = oldPlaneX * sin(obj->rotVelo * (mother->tickLength / 10000)) + obj->planeY * cos(obj->rotVelo * (mother->tickLength / 10000));
	}
}


/*
void	ft_moveLeft(t_w3d *mother, t_3di *ob3)
{
}

void	ft_moveRight(t_w3d *mother, t_3di *ob3)
{
}
*/
