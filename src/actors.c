/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:54:41 by adaly             #+#    #+#             */
/*   Updated: 2017/11/09 21:27:08 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void	ft_actor_turn(t_w3d *mother, t_actor *actor, char lr)
{
	t_3di	*obj;

	obj = NULL;
	if (mother && actor && (obj = &(actor->obj)))
	{
		obj->rotVelo = actor->acrobatics * (lr ? -1 : 1);
		ft_obj_rot(mother, &(actor->obj));
	}
}
