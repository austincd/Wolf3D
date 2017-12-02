/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 06:03:18 by adaly             #+#    #+#             */
/*   Updated: 2017/11/03 06:30:24 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf/libft.h"

typedef struct	s_ray
{
	long double		cameraX;
	long double		rayPosX;
	long double		rayPosY;
	long double		rayDirX;
	long double		rayDirY;
	int				mapX;
	int				mapY;
	long double		sideDistX;
	long double		sideDistY;
	long double		deltaDistX;
	long double		deltaDistY;
	long double		perpWallDist;
	int				stepX;
	int				stepY;
	int				hit;
	int				side;
}				t_ray;

typedef struct	s_w3d
{
	long double		posX;
	long double		posY;
	long double		planeX;
	long double		planeY;
	long double		dirX;
	long double		dirY;
	long double		time;
	long double		oldTime;
	int				resX;
	int				resY;
	t_frame			frame;
	t_map			map;
	t_texture		textures[NB_T];
}				t_w3d;
