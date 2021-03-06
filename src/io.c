/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 04:58:56 by adaly             #+#    #+#             */
/*   Updated: 2017/11/24 15:03:03 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void		ft_hooks(t_w3d *mother)
{
	if (mother)
	{
	mlx_do_key_autorepeatoff(mother->mlx.mlx);
	mlx_hook(mother->mlx.win, 2, 0, key_press_hook, mother);
	mlx_hook(mother->mlx.win, 3, 0, key_release_hook, mother);
//	mlx_hook(mother->mlx.win, 12, 0, expose_hook, mother);
	mlx_hook(mother->mlx.win, 17, 0, exit_hook, mother);
	mlx_loop_hook(mother->mlx.mlx, ft_loop, mother);
	}
}

int		ft_loop(t_w3d *mother)
{
	printf("p1x: %Lf p1y: %Lf p1dirX: %Lf p1dirY: %Lf\n", mother->p1.actor.obj.posX, mother->p1.actor.obj.posY, mother->p1.actor.obj.dirX, mother->p1.actor.obj.dirY);
	printf("p1cdirX %Lf p1cdirY %Lf\n", mother->p1.cam.dirX, mother->p1.cam.dirY);
	ft_p1Control(mother);
	if (mother->keys.turnLeft || mother->keys.turnRight)
	{
		ft_dirToCam(mother);
	}
	if (mother->p1.bonusDuration)
		printf("Bonus:%Lf\n", mother->p1.bonusDuration);
	if (mother->p1.actor.invul)
		printf("Invul:%Lf\n", mother->p1.actor.invul);
	if (mother->p1.actor.active)
		printf("Active:%Lf\n", mother->p1.actor.active);
	if (mother->keys.turnLeft)
		mother->keys.turnLeft += 1;
	if (mother->keys.turnRight)
		mother->keys.turnRight += 1;
	ft_physUpdateAll(mother);
	ft_render(mother);
	usleep(mother->tickLength);
	ft_decay(mother);
	return (0);
}

int		key_release_hook(int keycode, t_w3d *mother)
{
	if (keycode == KEY_ESCAPE || keycode == KEY_SHIFT_LEFT)
		;
	else if (keycode == KEY_W)
		mother->keys.forward = 0;
	else if (keycode == KEY_A)
		mother->keys.left = 0;
	else if (keycode == KEY_S)
		mother->keys.backward = 0;
	else if (keycode == KEY_D)
		mother->keys.right = 0;
	else if (keycode == KEY_LEFT)
	{
		if (mother->keys.turnLeft < (mother->tickRate / 2))
			mother->keys.fadeLeft = 1;
		mother->keys.turnLeft = 0;
	}
	else if (keycode == KEY_RIGHT)
	{
		if (mother->keys.turnRight < (mother->tickRate / 2))
			mother->keys.fadeRight = 1;
		mother->keys.turnRight = 0;
	}
	return (0);
}

int		key_press_hook(int keycode, t_w3d *mother)
{
	if (keycode == KEY_ESCAPE)
		exit_hook(mother);
	if (keycode == KEY_SPACEBAR)
		;//ft_attack(mother);
	else if (keycode == KEY_W)
		mother->keys.forward += 1;
	else if (keycode == KEY_A)
		mother->keys.left += 1;
	else if (keycode == KEY_S)
		mother->keys.backward += 1;
	else if (keycode == KEY_D)
		mother->keys.right += 1;
	else if (keycode == KEY_LEFT)
		mother->keys.turnLeft += 1;//ft_fade_left(mother);
	else if (keycode == KEY_RIGHT)
		mother->keys.turnRight += 1;//ft_fade_right(mother);
	else if (keycode == KEY_UP)
		mother->p1.bonusDuration += 2.5;//ft_tech_forward(mother);
	else if (keycode == KEY_DOWN)
		mother->p1.actor.invul += 2.5;//ft_tech_backward(mother);
	return (0);
}

void			ft_p1Control(t_w3d *mother)
{
	if (mother)
	{
		if (mother->keys.forward)
		{
			printf("moving forward!\n");
			mother->p1.actor.obj.dirX = mother->p1.cam.dirX;
			mother->p1.actor.obj.dirY = mother->p1.cam.dirY;
			mother->p1.actor.obj.velo = mother->p1.actor.agility;
//			ft_moveForward(mother, &(mother->p1.actor.obj));
		}
		if (mother->keys.backward)
		{
			printf("moving backward!\n");
			mother->p1.actor.obj.dirX = mother->p1.cam.dirX * -1;
			mother->p1.actor.obj.dirY = mother->p1.cam.dirY * -1;
			mother->p1.actor.obj.velo = mother->p1.actor.agility;
//			ft_moveBackward(mother, &(mother->p1.actor.obj));
		}
		if (mother->keys.turnLeft >= (mother->tickRate / 5))
		{
			printf("turning left!\n");
			mother->p1.cam.rotVelo = mother->p1.actor.acrobatics;
//			ft_actor_turn(mother, &(mother->p1.actor), 0);
		}
		if (mother->keys.turnRight >= (mother->tickRate / 5))
		{
			printf("turning right!\n");
			mother->p1.cam.rotVelo = mother->p1.actor.acrobatics * -1;
//			ft_actor_turn(mother, &(mother->p1.actor), 1);
		}
		if (mother->keys.fadeLeft == 1)
		{
			printf("dodging left!\n");
			ft_fadeLeft(mother);
			mother->keys.fadeLeft = 0;
		}
		if (mother->keys.fadeRight == 1)
		{
			printf("dodging right!\n");
			ft_fadeRight(mother);
			mother->keys.fadeRight = 0;
		}
	}
}

int		exit_hook(t_w3d *mother)
{
	int i;

	i = -1;
	if (mother)
	{
		if (mother->mlx.mlx && mother->mlx.win)
			mlx_destroy_window(mother->mlx.mlx, mother->mlx.win);
		mlx_destroy_image(mother->mlx.mlx, mother->mlx.frame.framePtr);
		ft_bzero(mother, sizeof(t_w3d));
	}
	exit(0);
}
