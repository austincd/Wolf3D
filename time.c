# include <time.h>

void timing(t_w3d *mother)
{
	double	ftime;
	double	ttime;
	
	if (mother->time.target_fps && mother->time.target_tps)
	{
		ftime = 1.0000 / mother->time.target_fps;
		ttime = 1.0000 / mother->time.target_tps;
		mother->time.frame = ftime;
		mother->time.tick = ttime;
	}
}

typedef struct	s_actor
{
	int		hp;
	int		defense;
	int		agility;
	int		acrobatics;
	float	bonus;
//	t_weapon	weapons[LIMIT_WEAPONS];
	t_ob2	obj;
}				t_actor;

void	ft_ob2_turn(t_w3d *mother, t_actor *actor, char lr)
{
	if (mother && actor && (obj = actor->obj))
	{
		obj->rotVelo = actor->acrobatics * (lr ? -1 : 1);
	}
}

/*void	ft_ob2_rotRight(t_w3d *mother, t_ob3 *obj)
{
		if (mother && obj)
		{
			oldDirX = obj->dirX;
			oldPlaneX = obj->planeX;
			obj->dirX *= cos(-1 * obj->rotVelo) - dirY * sin(-1 * obj->rotVelo);
			obj->dirY = oldDirX * sin(-1 * obj->rotVelo) + obj->dirY * cos(-1 * obj->rotVelo);
			obj->planeX = obj->planeX * cos(-1 * obj->rotVelo) - obj->planeY * sin(-1 * obj->rotVelo);
			obj->planeY = oldPlaneX * sin(-1 * obj->rotVelo) + obj->planeY * cos(-1 * obj->rotVelo);
		}
}*/

void	ft_ob2_rotLeft(t_w3d *mother, t_ob3 *obj)
{
		if (mother && obj)
		{
			oldDirX = obj->dirX;
			oldPlaneX = obj->planeX;
			obj->dirX *= cos(obj->rotVelo) - dirY * sin(obj->rotVelo);
			obj->dirY = oldDirX * sin(obj->rotVelo) + obj->dirY * cos(obj->rotVelo);
			obj->planeX = obj->planeX * cos(obj->rotVelo) - obj->planeY * sin(obj->rotVelo);
			obj->planeY = oldPlaneX * sin(obj->rotVelo) + obj->planeY * cos(obj->rotVelo);
		}
}

// add nanosleep() to ft_loop;
