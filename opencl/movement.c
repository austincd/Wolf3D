/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:52:02 by adaly             #+#    #+#             */
/*   Updated: 2017/11/08 20:00:52 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

__kernel void ft_oCl_movement(__global t_w3d *mother)
{
	const int	i;
	const t_3di	*myObj;

	i = get_global_id(0);
	myObj = mother->objs + i;
	if (myObj->velo > 0)
	{
		if (!(ft_isSolid(mother, ((int)myObj->posX + myObj->dirX * \
		myObj->velo), int(myObj->posY))))
			myObj->posX += myObj->dirX * myObj->velo;
		else
		{
//			myObj->posX = (long double)((int)(myObj->posX + \
			myObj->dirX * myObj->velo))
			myObj->hitX = ((int)myObj->posX + myObj->dirX * myObj->velo);
		}
		if (!(ft_isSolid(mother, int(myObj->posX), ((int)myObj->posY + myObj->dirY * \
		myObj->velo))))
			myObj->posY += myObj->dirY * myObj->velo;
		else
		{
			myObj->hitY = ((int)myObj->posY + myObj->dirY * myObj->velo);
		}
	}
}

void	ft_check_collisions()
{
	int	diff;
	int	counter;

	counter = -1;
	if ((int)oldX != (int)newX)
	{
		diff = ft_absval(int(oldX) - int(newX));
		if (int(oldX) > int(newX))
		{
			while(++counter < diff)
			{
				if (ft_occupied(mother, int(oldX) - counter))
					ft_collide(mother, myObj);
			}
		}
		else
		{
			while(++counter < diff)
			{
				if (ft_occupied(mother, int(oldX) + counter))
					ft_collide(mother, myObj);
			}
		}
	}
}

/*		myObj->deltaDistX = sqrt(1 + (myObj->dirY * myObj->dirY) / \
		(myObj->dirX * myObj->dirX));
		myObj->deltaDistY = sqrt(1 + (myObj->dirX * myObj->dirX) / \
		(myObj->dirY * myObj->dirY));
		if (myObj->dirX < 0)
		{
			myObj->stepX = -1;
			myObj->sideDistX = (myObj->posX - mother->map.mapX) * \
			myObj->deltaDistX;
		}
		else
		{
			myObj->stepX = 1;
			myObj->sideDistX = (mother->mapX + 1.0 - myObj->posX) * \
			myObj->deltaDistX;
		}
		if (myObj->dirY < 0)
		{
			myObj->stepY = -1;
			myObj->sideDistY = (myObj->posY - mother->map.mapY) * \
			myObj->deltaDistY;
		}
		else
		{
			myObj->stepY = 1;
			myObj->sideDistY = (mother->mapY + 1.0 - myObj->posY) * \
			myObj->deltaDistY;
		}*/
