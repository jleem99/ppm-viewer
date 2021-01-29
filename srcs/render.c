/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 06:39:33 by jleem             #+#    #+#             */
/*   Updated: 2021/01/29 10:34:57 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "mlx_global.h"
#include "libft.h"
#include "get_next_line.h"
#include "util.h"

void	render_pixel(t_mlx_global *global, int r, int g, int b)
{
	static int	x;
	static int	y;

	if (y >= global->height)
	{
		ft_putendl_fd("Img out of bound!", 2);
		exit(-1);
	}
	img_put_pixel(global->img, x, y, (0xFF << 24 | r << 16 | g << 8 | b));
	if (++x == global->width)
	{
		x = 0;
		y++;
	}
}

void	render(t_mlx_global *global, int fd)
{
	char	*line;
	char	**split;
	int		retcode;
	int		i;

	while ((retcode = get_next_line(fd, &line)) > 0)
	{
		if ((split = ft_split(line, ' ')))
		{
			i = 0;
			while (split[i] && split[i + 1] && split[i + 2])
			{
				render_pixel(global, ft_atoi(split[i]), ft_atoi(split[i + 1]), ft_atoi(split[i + 2]));
				i += 3;
			}
			ft_split_free(split);
		}
		free(line);
	}
	if (retcode == 0)
		free(line);
	mlx_put_image_to_window(global->mlx, global->win, global->img->img, 0, 0);
	mlx_loop(global->mlx);
}
