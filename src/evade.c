/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 05:06:39 by adaly             #+#    #+#             */
/*   Updated: 2017/11/13 06:12:35 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_fadeLeft(t_w3d *mother)
{
	t_player	*player;

	if (mother && mother->player && (player = mother->p1) && \
	player->active <= 0)
	{
		mother->p1.actor.obj.dirX = mother->p1.cam.obj.dirY * -1;
		mother->p1.actor.obj.dirY = mother->p1.cam.obj.dirX * -1;
		mother->p1.actor.obj.velo = mother->p1.actor.agility * 3;
		player->active = pl->fade_duration;
		player->invul = mother->fade_iframes;
		ft_moveForward(mother, &(mother->p1.actor.obj));
//		player->bonusMass = 2;
	}
}

void	ft_fadeRight(t_w3d *mother)
{
	t_player	*player;

	if (mother && mother->player && (player = mother->p1) && \
	player->active <= 0)
	{
		mother->p1.actor.obj.dirX = mother->p1.cam.obj.dirY;
		mother->p1.actor.obj.dirY = mother->p1.cam.obj.dirX;
		mother->p1.actor.obj.velo = mother->p1.actor.agility * 3;
		player->active = pl->fade_duration;
		player->invul = mother->fade_iframes;
		ft_moveForward(mother, &(mother->p1.actor.obj));
//		player->bonusMass = 2;
	}
}

void	ft_tech(t_w3d *mother)
{
	t_player	*player;

	if (mother && mother->player && (player = mother->player) && \
	player->active <= 0)
	{
		if (ft_tech_validate(mother))
		{
			player->bonus += 0.1;
			player->bonus_timer = player->bonus_maxtime;
			player->active = player->tech_time;
			ft_scoreup(mother, 100);
		}
		else
		{
			player->active = player->tech_penalty;
		}
	}
}

void	ft_tech_up(t_w3d *mother)
{
	if (mother && mother->p1.techUpWindow)
	{
		mother->p1.bonus += 0.1;
		mother->p1.bonusDuration = maxBonusDuration;
		mother->p1.actor.invul += (mother->p1.bonus * 0.5);
	}
}

void	ft_tech_down(t_w3d *mother)
{
	if (mother && mother->p1.techDownWindow)
	{
		mother->p1.bonus += 0.1;
		mother->p1.bonusDuration = maxBonusDuration;
		mother->p1.actor.invul += (mother->p1.bonus * 0.5);
	}
}

/*void	ft_fade_left(t_w3d *mother)
{
	if (mother && !(mother->p1.actor.active))
	{

	}
}*/
