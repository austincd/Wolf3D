/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 04:20:16 by adaly             #+#    #+#             */
/*   Updated: 2017/11/24 05:35:09 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

// t_ray	ft_prepare_ray(t_w3d *mother, int x)
// {
// 	t_ray	new_ray;
//
// 	ft_bzero(&new_ray, (sizeof(t_ray)));
// 	if (mother)
// 	{
// 		new_ray.cameraX = 2*x/double(mother->resX)-1; //x-coordinate in camera space
// 		new_ray.rayPosX = mother->posX;
// 		new_ray.rayPosY = mother->posY;
// 		new_ray.rayDirX = mother->dirX + mother->planeX*mother->cameraX;
// 		new_ray.rayDirY = mother->dirY + mother->planeY*mother->cameraX;
// 	}
// 	return (new_ray);
// }
//
// void	ft_render_column(t_w3d *mother, int x)
// {
// 	t_ray	ray;
//
// 	if (mother && x >= 0)
// 	{
// 		ray = ft_prepare_ray(mother, x);
// 		ft_render_wall(mother, &ray, x);
// 		ft_render_ceiling(mother, &ray, x);
// 		ft_render_floor(mother, &ray, x);
// 	}
// }

static void ft_rayStats(t_ray *ray)
{
	if (ray)
	{
//		printf("posX:%Lf\n", ray->obj.posX);
//		printf("posY:%Lf\n", ray->obj.posY);
//		printf("dirX:%Lf\n", ray->obj.dirX);
//		printf("dirY:%Lf\n", ray->obj.dirY);
//		printf("Hit:%i\n", ray->hit);
//		printf("Side:%i\n", ray->side);
//		printf("dStart:%i\n", ray->drawStart);
//		printf("dEnd:%i\n", ray->drawEnd);
	}
}

void ft_raycast(t_w3d *mother, t_ray *ray) {
	if (mother && ray)
	{
//		printf("one\n");
		ft_stepnside(mother, ray);
//		printf("two\n");
		ft_dda(mother, ray);
//		printf("three\n");
		ft_stripe(mother, ray);
//		printf("four\n");
		ft_rayTex(mother, ray);
//		printf("five\n");
		ft_rayDraw(mother, ray);
		ft_rayStats(ray);
	}
}
void ft_raycast_all(t_w3d *mother)
{
	int	counter;

	counter = 0;
	if (mother && mother->resX)
	{
		while (counter < mother->resX)
		{
//			printf("counter is %i\n", counter);
			ft_raycast(mother, mother->rays + counter);
			++counter;
		}
	}
}
void ft_render(t_w3d *mother)
{
	if (mother)
	{
//		printf("testing!\n");
		ft_allocate_rays(mother);
//		printf("testing2!\n");
		ft_bzero(mother->rays, sizeof(t_ray) * mother->resX);
		ft_prepare_rays(mother);
//		printf("testing3!\n");
		ft_raycast_all(mother);
//		printf("testing4!\n");
		mlx_put_image_to_window(mother->mlx.mlx, mother->mlx.win, mother->mlx.frame.framePtr, 0, 0);
		ft_framebuffer_forget(mother);
	}
}
