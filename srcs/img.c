/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:44:56 by jleem             #+#    #+#             */
/*   Updated: 2021/01/11 01:42:11 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "img.h"
#include <mlx.h>
#include <stdlib.h>

t_img			*init_img(void *mlx, int width, int height)
{
	t_img	*img;

	if (!(img = malloc(sizeof(t_img))))
		return (NULL);
	img->img = mlx_new_image(mlx, width, height);
	img->addr = mlx_get_data_addr(img->img,
									&img->bits_per_pixel,
									&img->line_length,
									&img->endian);
	return (img);
}

void			img_put_pixel(t_img *img, int x, int y, int color)
{
	int const	offset = y * img->line_length + x * (img->bits_per_pixel / 8);
	int *const	dst = (int *)(img->addr + offset);
	*(dst) = color;
}
