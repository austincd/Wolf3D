/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   framebuffer_ops.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 05:10:45 by adaly             #+#    #+#             */
/*   Updated: 2017/11/21 17:57:43 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

/*
**Simple, short list of functions that affect the frame buffer provided by MLX.
**
**	ft_framebuffer_forget:	Uses ft_bzero to completely clear the buffer.
**							Used before rendering a new frame to destroy
**							leftover data from previous renders.
**	ft_plot:				plots a color on the frame buffer according
**							to given coordinates and a color id, which
**							is first translated to an actual color value
**							by ft_coloring_book.
**
**The MiniLibX library includes a utility for not just placing individual
**pixels in a window, but also for generating an entire image, and subse-
**quently placing an image on screen. Taking advantage of this provides a
**significant advantage in speed, and also seems to more accurately refl-
**ect most graphical systems, which typically have some kind of frame bu-
**ffer, where the image on screen is calculated before being displayed.
**
**MLX doesn't include functions to access a specific pixel in the frame
**buffer. We can only use the mlx_get_data_addr function to get:
**
**	A:	The start of the framebuffer in memory as a char*.
**	B:	The number of bits for each pixel, which varies by display;
**	C:	The number of bytes in each line;
**
**Using these, we can navigate to the memory location of a pixel at
**(x, y) in the frame by the ptr A, and advancing a certain number
**of bytes, N.
**
**	N = (C * y) + ((B / 8) * x);
**
**since C gives us the number of bytes we need to advance a line,
**and we increment a char* by one byte at a time, no conversion is
**needed. B is a number of bits, though, so we need to divide it by
**the number of bits in a byte to know how much we need to increment
**a char* to move forward by one pixel. This is simple enough as long
**as we assume that assume that each pixel occupies a whole number of
**bytes, and that each byte only contains the data for one pixel. As we
**can only access memory addresses down to the byte, we'd need to use
**a number of bitwise operations to write a value to every byte that
**respects the bit patterns of all pixels with data in that byte.
**
**Thankfully, we can sidestep this if we don't need compatibility with
**any and every device. Most systems capable of displaying 4096 colors or
**more are either 16, 24, or 32 bits per pixel, which are all divisible by
**8. For this FDF, those are the three values that are supported.
**
**Using this information, ft_mlximg_nav takes in the struct with all our
**info, as well as some x,y coordinates that we understand, and then uses
**these values to find and return the memory location of the pixel we want.
**ft_mlximg_plot takes advantage of this when we tell it to write a color
**value to a pixel located at (x, y);
**
**mlx_get_color_value is used to find the closest representation of a color
**with respect to the color depth of the current MLX environment. 16 bit
**and 32 bit color are both written using a variable of equivalent size,
**and 24 bit color values are written with ft_mlximg_bpp24, which writes the
**relevant 3 bytes of the integer returned by mlx_get_color_value to the
**framebuffer, selecting the 3 bytes with respect to the endian of the
**system.
*/

static void	ft_mlximg_bpp24(t_mlx *mlx, char *pxpt, unsigned int color_code)
{
	char	*clr_ptr;

	clr_ptr = NULL;
	if (mlx && pxpt && color_code && mlx->bppx == 24)
	{
		clr_ptr = (char*)&color_code;
		if (mlx->endi)
		{
			pxpt[0] = clr_ptr[1];
			pxpt[1] = clr_ptr[2];
			pxpt[2] = clr_ptr[3];
		}
		else
		{
			pxpt[0] = clr_ptr[0];
			pxpt[1] = clr_ptr[1];
			pxpt[2] = clr_ptr[2];
		}
	}
}

void		*ft_mlximg_nav(t_mlx *mlx, int x, int y)
{
	void	*line;
	t_frame	*frame;
	int		first_byte;

	line = NULL;
	first_byte = -1;
	frame = NULL;
	if (mlx)
		frame = &(mlx->frame);
	if (frame && frame->frameData && mlx->bppx && mlx->bpln)
	{
		line = (frame->frameData + (mlx->bpln * y));
		if (line)
		{
			first_byte = (mlx->bppx % 8) ? -1 : ((mlx->bppx / 8) * x);
		}
	}
	if (first_byte == -1)
		return (NULL);
	return (line + first_byte);
}
//
// void		*ft_create_image(t_w3d *mother, t_frame *frame)
// {
// 	void	*image;
//
// 	image = NULL;
// 	if (mother && frame)
// 	{
// 		image = mlx_new_image(mother->mlx, mother->res_x, mother->res_y);
// 		if (image)
// 		{
// 			frame->img = image;
// 			frame->img_start = mlx_get_data_addr(frame->img, &frame->bpp, \
// 			&frame->szln, &frame->endi);
// 		}
// 	}
// 	return (image);
// }

void	ft_framebuffer_forget(t_w3d *mother)
{
	int		num_bytes;
	t_mlx	*mlx;

	num_bytes = 0;
	if (mother && (mlx = &(mother->mlx)))
	{
		if (mlx && mlx->frame.framePtr && mlx->frame.frameData)
		{
			num_bytes = mlx->bpln * mother->resY;
			ft_bzero(mlx->frame.frameData, num_bytes);
		}
	}
}

void	ft_mlx_ppp(t_w3d *mother, int x, int y, t_pix color)
{
	char			*pxpt;
	unsigned char	*cl;
	unsigned int	color_code;
	t_frame			*frame;

	pxpt = NULL;
	color_code = 0;
	cl = (unsigned char*)&color_code;
	cl[0] = color.r;
	cl[1] = color.g;
	cl[2] = color.b;
	cl[3] = color.alpha;
	frame = mother ? &(mother->mlx.frame) : NULL;
	if (frame && color_code)
	{
		pxpt = (char*)ft_mlximg_nav(&(mother->mlx), x, y);
		color_code = mlx_get_color_value(mother->mlx.mlx, color_code);
		if (color_code && pxpt)
		{
			if (mother->mlx.bppx == 32)
				*((unsigned int*)pxpt) = color_code;
			else if (mother->mlx.bppx == 16)
				*((unsigned short*)pxpt) = (short)color_code;
			else if (mother->mlx.bppx == 24)
				ft_mlximg_bpp24(&(mother->mlx), pxpt, color_code);
		}
	}
}
