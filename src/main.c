/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 05:57:05 by adaly             #+#    #+#             */
/*   Updated: 2017/11/24 14:17:02 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void	ft_prepare(t_w3d *mother)
{
	if (mother)
	{
		ft_bzero(mother, sizeof(t_w3d));
		ft_strcat(mother->mapName.path, "default");
		ft_strcat(mother->mapConf.path, "default/config");
		ft_strcat(mother->genConf.path, "profile.conf");
		mother->mapName.fd = ft_open_file(mother->mapName.path);
		mother->mapConf.fd = ft_open_file(mother->mapConf.path);
		mother->genConf.fd = ft_open_file(mother->genConf.path);
	}
}

int		ft_mlxPrep(t_w3d *mother)
{
	if (mother)
	{
		mother->mlx.mlx = mlx_init();
		mother->mlx.win = mlx_new_window(mother->mlx.mlx, mother->resX, \
		mother->resY, mother->mapName.path);
		mother->mlx.frame.framePtr = mlx_new_image(mother->mlx.mlx, mother->resX, mother->resY);
		mother->mlx.frame.frameData = (unsigned int *)mlx_get_data_addr(mother->mlx.frame.framePtr, \
		&(mother->mlx.bppx), &(mother->mlx.bpln), &(mother->mlx.endi));
		if (mother->mlx.frame.framePtr)
			return (1);
	}
	return (0);
}

int		ft_loadProfile(t_w3d *mother)
{
	int		status;
	char	*line;

	line = NULL;
	if (mother && (mother->genConf.fd >= 0))
	{
		while ((status = get_next_line(mother->genConf.fd, &line) == 1))
		{
			if (ft_strnequ(line, "resX:", 5))
				mother->resX = ft_atoi(line + 5);
			if (ft_strnequ(line, "resY:", 5))
				mother->resY = ft_atoi(line + 5);
			if (ft_strnequ(line, "tickRate:", 9))
				mother->tickRate = ft_atoi(line + 9);
			ft_strdel_plus(&line);
		}
		ft_timing(mother);
		return (1);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_w3d		mother;

	ft_prepare(&mother);
	if (argc == 2)
		ft_strcat(mother.mapName.path, argv[1]);
	if (argc == 3)
		ft_strcat(mother.genConf.path, argv[2]);
	if (ft_loadProfile(&mother))
	{
		ft_readConf(&mother);
		ft_mlxPrep(&mother);
		ft_loadWalls(&mother);
		mother.p1.actor.obj.mass = 15;
		mother.p1.cam.mass = 15;
		mother.p1.actor.agility = 0.1;
		mother.p1.actor.acrobatics = 0.1;
		mother.p1.cam.dirX = -1.0;
		mother.p1.cam.dirY = 0;
		mother.p1.cam.planeX = 0.0;
		mother.p1.cam.planeY = 0.66;
		mother.p1.actor.obj.dirX = -1.0;
		mother.p1.actor.obj.dirY = 0.0;
		ft_testTex(&mother);
//		ft_printTex(mother.textures);
//		getchar();
		ft_putendl("OK0!");
		ft_hooks(&mother);
		ft_putendl("OK1!");
		mlx_loop(mother.mlx.mlx);
		ft_putendl("OK!");
	}
}


void	ft_error(int code, t_w3d *mother)
{
	if (mother)
	{
		if (code == -1)
			ft_putendl_fd("MAP DIMENSIONS TOO LARGE! LIMIT FOR X = MAX_X; \
			LIMIT FOR Y = MAX_Y", 2);
		else if (code == -2)
			ft_putendl_fd("INVALID PROFILE! PLEASE PROVIDE ONE IN THE \
			DEFAULT LOCATION(./profile.conf) OR CHANGE TARGET PATH!", 2);
		else if (code == -3)
			ft_putendl_fd("NONEXISTENT OR INVALID MAP! PLEASE PROVIDE A \
			DEFAULT OR CHANGE TARGET PATH", 2);
		else if (code == -4)
			ft_putendl_fd("CORRUPT OR INVALID MAP!", 2);
	}
}
