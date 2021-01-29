/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_global.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 18:17:11 by jleem             #+#    #+#             */
/*   Updated: 2021/01/29 08:04:55 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_global.h"
#include <mlx.h>
#include <stdlib.h>

t_mlx_global	*init_mlx_global(int width, int height, char *title)
{
	t_mlx_global	*global;

	if ((global = malloc(sizeof(t_mlx_global))) &&
		(global->mlx = mlx_init()) &&
		(global->win = mlx_new_window(global->mlx, width, height, title)) &&
		(global->img = init_img(global->mlx, width, height)))
	{
		global->width = width;
		global->height = height;
		return (global);
	}
	return (NULL);
}

void			free_mlx_global(t_mlx_global *global)
{
	if (global)
	{
		if (global->mlx)
		{
			if (global->win)
			{
				mlx_destroy_image(global->mlx, global->img->img);
				mlx_destroy_window(global->mlx, global->win);
				free(global->img);
			}
			free(global->mlx);
		}
		free(global);
	}
}
