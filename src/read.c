/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 23:51:01 by adaly             #+#    #+#             */
/*   Updated: 2017/11/09 21:23:12 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void		ft_loadWalls(t_w3d *mother)
{
	int		status;
	int		counter;
	char	*line;

	line = NULL;
	counter = 0;
	if (mother)
	{
		mother->map.wallMap.fd = ft_open_file(mother->map.wallMap.path);
		if (mother->map.wallMap.fd >= 0)
		{
			while ((status = get_next_line(mother->map.wallMap.fd, &line)))
			{
//				printf("line is %s\nft_strlen is %zu\n", line, ft_strlen(line));
				ft_strcat(mother->map.walls[counter].col, line);
				if ((intmax_t)ft_strlen(line) != mother->map.mapX + 1)
					ft_error(-4, mother);
				ft_strdel_plus(&line);
				++counter;
			}
			if (counter != mother->map.mapY + 1)
				ft_error(-4, mother);
//			printf("counter is %i\n", counter);
		}
	}
}

void		ft_readConf(t_w3d *mother)
{
	int		status;
	char	*line;

	line = NULL;
	if (mother && mother->mapConf.fd >= 0)
	{
		ft_strcat(mother->map.wallMap.path, mother->mapName.path);
		ft_strcat(mother->map.wallMap.path, "/");
		while ((status = get_next_line(mother->mapConf.fd, &line)))
		{
//			printf("line is %s\n", line);
			if (ft_strnequ(line, "mapX:", 5))
				mother->map.mapX = ft_atoi(line + 5);
			if (ft_strnequ(line, "mapY:", 5))
				mother->map.mapY = ft_atoi(line + 5);
			if (ft_strnequ(line, "wallMap:", 8))
				ft_strcat(mother->map.wallMap.path, line + 8);
			if (ft_strnequ(line, "spawnX:", 7))
				mother->p1.actor.obj.posX = ft_atoi(line + 7); //change from atoi to atof
			if (ft_strnequ(line, "spawnY:", 7))
				mother->p1.actor.obj.posY = ft_atoi(line + 7); //change from atoi to atof
			ft_strdel_plus(&line);
		}
		printf("map dimensions are %i, %i\n", mother->map.mapX, mother->map.mapY);
		printf("wallMap path is %s\n", mother->map.wallMap.path);
	}
}
