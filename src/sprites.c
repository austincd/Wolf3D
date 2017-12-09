void	ft_spriteSort(t_w3d *mother)
{
	int	counter;
	double posX;
	double posY;

	counter = 0;
	posX = mother->p1.actor.obj.posX;
	posY = mother->p1.actor.obj.posY;
	while (counter < mother->numSprites)
	{
		mother->spriteOrder[counter] = counter;
		mother->spriteDistance[counter] = ((posX - sprite[counter].x) * \
		(posX - sprite[counter].x) + (posY - sprite[counter].y) * \
		(posY - sprite[counter].y));
		++counter;
	}
	combSort(mother->spriteOrder, mother->spriteDistance, mother->numSprites);
}

void	ft_spriteProjection(t_w3d *mother)
{
}

void	ft_spriteDraw(t_w3d *mother)
{
}
