typedef struct	s_sprite
{
	t_img		*frames;
	int			numFrames;
	double		timePerFrame;
	int			resX;
	int			resY;
}				t_sprite;

int				ft_tImgLoadHeader(t_file *img)
{
	char	*line;

	line = NULL;
	if (img && img->fd >= 0)
	{
		if ((status = get_next_line(img->fd, &line)))
		{
			img->resX = ft_atoi(line);
			img->resY = ft_atoi(ft_strchr(line, ':'));
			img->bytppx = ft_atoi(ft_strchr(line, ';'));
			ft_strdel_plus(&line);
		}
	}
}

unsigned char	ft_hexToByte(char *hex)
{
	unsigned char	byte;
	char			digits[17];

	byte = 0;
	ft_bzero(digits, sizeof(char) * 17);
	ft_strcpy(digits, "0123456789ABCDE");
	if (hex && ft_isalnum(hex[0]) && ft_isalnum(hex[1]))
	{
		byte = 16 * (ft_strchr(digits, hex[0]) - digits);
		byte += (ft_strchr(digits, hex[1]) - digits);
	}
	return (byte);
}

void			ft_tImgRead(void *imgData, t_file *img)
{
	int				counter;
	unsigned char	*target;

	counter = 0;
	target = (unsigned char)imgData;
	while (counter < img->bytes)
	{
		target[counter] = ft_hexToByte(line + (counter * 2));
		++counter;
	}
}

int				ft_tImgLoad(t_file *img)
{
	if (img)
	{
		if ((img->bytes = img->resX * img->resY * img->bytppx))
		{
			img->imgData = ft_memalloc_plus(memory, bytes);
			ft_tImgRead(imgData, img);
		}
	}
}