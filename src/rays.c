/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 22:07:54 by adaly             #+#    #+#             */
/*   Updated: 2017/11/24 05:35:43 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void	ft_allocate_rays(t_w3d *mother)
{
	if (mother && !mother->rays)
		mother->rays = (t_ray*)ft_memalloc(sizeof(t_ray) * mother->resX);
}

void	ft_stepnside(t_w3d *mother, t_ray *ray)
{
	if (mother && mother->rays && ray)
	{
		if (ray->obj.dirX < 0)
		{
			ray->stepX = -1;
			ray->sideDistX = (ray->obj.posX - ray->mapX) * ray->deltaDistX;
		}
		else
		{
			ray->stepX = 1;
			ray->sideDistX = (ray->mapX + 1.0 - ray->obj.posX) * ray->deltaDistX;
		}
		if (ray->obj.dirY < 0)
		{
			ray->stepY = -1;
			ray->sideDistY = (ray->obj.posY - ray->mapY) * ray->deltaDistY;
		}
		else
		{
			ray->stepY = 1;
			ray->sideDistY = (ray->mapY + 1.0 - ray->obj.posY) * ray->deltaDistY;
		}
	}
}

void	ft_dda(t_w3d *mother, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->sideDistX < ray->sideDistY)
		{
			ray->sideDistX += ray->deltaDistX;
			ray->mapX += ray->stepX;
			ray->side = 0;
		}
		else
		{
			ray->sideDistY += ray->deltaDistY;
			ray->mapY += ray->stepY;
			ray->side = 1;
        }
		if (mother->map.walls[ray->mapY].col[ray->mapX] > '0') ray->hit = 1;
	}
	if (ray->side == 0)
		ray->perpWallDist = (ray->mapX - ray->obj.posX + (1 - ray->stepX) / 2) / ray->obj.dirX;
	else
		ray->perpWallDist = (ray->mapY - ray->obj.posY + (1 - ray->stepY) / 2) / ray->obj.dirY;

}

void	ft_stripe(t_w3d *mother, t_ray *ray)
{
	if (mother && ray)
	{
		ray->lineHeight = (int)(mother->resY / ray->perpWallDist);
//		printf("lineHeight = %i\nperpDist = %Lf\n", ray->lineHeight, ray->perpWallDist);
		ray->drawStart = ((-1 * ray->lineHeight) / 2) + (mother->resY / 2);
		if (ray->drawStart < 0)
			ray->drawStart = 0;
		ray->drawEnd = (ray->lineHeight / 2) + (mother->resY / 2);
		if (ray->drawEnd >= mother->resY)
			ray->drawEnd = mother->resY - 1;
//		if (ray->drawEnd < 0)
//			ray->drawEnd = 0;
	}
}

void	ft_prepare_rays(t_w3d *mother)
{
	int		counter;
	t_ray	*ray;
	t_3di	*obj;

	counter = 0;
	while (counter < mother->resX)
	{
		ray = mother->rays + counter;
		obj = &(ray->obj);
		obj->posX = mother->p1.actor.obj.posX;
		obj->posY = mother->p1.actor.obj.posY;
		ray->mapX = (int)(obj->posX);
		ray->mapY = (int)(obj->posY);
		ray->cameraX = 2 * counter / (double)mother->resX - 1;
		obj->dirX = mother->p1.cam.dirX + mother->p1.cam.planeX * ray->cameraX;
		obj->dirY = mother->p1.cam.dirY + mother->p1.cam.planeY * ray->cameraX;
	    ray->deltaDistX = sqrt(1 + (obj->dirY * obj->dirY) / (obj->dirX * obj->dirX));
	    ray->deltaDistY = sqrt(1 + (obj->dirX * obj->dirX) / (obj->dirY * obj->dirY));
		ray->x = counter;
		++counter;
	}
}

void ft_rayTex(t_w3d *mother, t_ray *ray)
{

	if (mother && mother->rays && ray)
	{
		ray->texNum = mother->map.walls[ray->mapY].col[ray->mapX] - '1';
		//printf("texNum = %d\n", ray->texNum);
		//getchar();
		if (ray->side == 0)
			ray->wallX = ray->obj.posY + ray->perpWallDist * ray->obj.dirY;
		else
			ray->wallX = ray->obj.posX + ray->perpWallDist * ray->obj.dirX;
		ray->wallX -= floor((ray->wallX));
		ray->texX = (int)(ray->wallX * ((double)(mother->textures[ray->texNum].texWidth)));
		if (ray->side == 0 && ray->obj.dirX > 0)
			ray->texX = mother->textures[ray->texNum].texWidth - ray->texX - 1;
		if (ray->side == 1 && ray->obj.dirY < 0)
			ray->texX = mother->textures[ray->texNum].texWidth - ray->texX - 1;
	}
}

void ft_testTex(t_w3d *mother) {
	int ctx;
	int cty;

	ctx = 0;
	cty = 0;
	if (mother)
	{
		mother->textures = (t_tex*)ft_memalloc(sizeof(t_tex));
		if (mother->textures)
		{
			mother->textures[0].texHeight = LIMIT_TEXRES;
			mother->textures[0].texWidth = LIMIT_TEXRES;
			while (cty < LIMIT_TEXRES)
			{
				while (ctx < LIMIT_TEXRES)
				{
					if (ctx % 2 == 0)
					{
						mother->textures[0].row[cty].col[ctx].r = 255;
						mother->textures[0].row[cty].col[ctx].g = 255;
						mother->textures[0].row[cty].col[ctx].b = 255;
						//mother->textures[0].row[cty].col[ctx].alpha = 255;
					}
					++ctx;
				}
				++cty;
				ctx = 0;
			}
		}
	}
}

void ft_printTex(t_tex *tex)
{
	t_pix col;
	int		ctx = 0;
	int		cty = 0;
	if (tex)
	{
		while (cty < LIMIT_TEXRES)
		{
			while (ctx < LIMIT_TEXRES)
			{
				col = tex->row[cty].col[ctx];
				//printf("r:%i g:%i b:%i al:%i\n", col.r, col.g, col.b, col.alpha);
				++ctx;
			}
			++cty;
			ctx = 0;
		}
	}
}

void	ft_rayDraw(t_w3d *mother, t_ray *ray)
{
	int		yCount;
	int		d;
	t_pix	color;
	t_tex	*texture;

	d = 0;
	ft_bzero(&color, sizeof(t_pix));
	texture = NULL;
	//color.r = 255;
	if (mother && mother->rays && ray)
	{
		yCount = ray->drawStart;
		// texture = &(mother->textures[ray->texNum]);
		texture = mother->textures;
		while (texture && yCount < ray->drawEnd)
		{
			//color.r = 255;
		//
		 	d = yCount * 256 - mother->resY * 128 + ray->lineHeight * 128;
			//printf("d is %i\n", d);
	 		ray->texY = ((d * texture->texHeight) / ray->lineHeight) / 256;
			//printf("texY is %d\n", ray->texY);
			//if (ray->texY >= 0)
		 	color = texture->row[ray->texY].col[ray->texX];
//			printf("r:%i g:%i b:%i al:%i\n", color.r, color.g, color.b, color.alpha);
			if (ray->side == 1)
			{
		 		color.r /= 2;
		 		color.g /= 2;
		 		color.b /= 2;
			}
//			printf("ray->x: %i\n", ray->x);
			ft_mlx_ppp(mother, ray->x, yCount, color);
			++yCount;
		}
	}
}
