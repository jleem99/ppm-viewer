/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 02:59:34 by jleem             #+#    #+#             */
/*   Updated: 2021/01/29 09:52:46 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "validate.h"
#include "mlx_global.h"
#include "render.h"

int		main(int argc, char const *argv[])
{
	int				fd;
	int				col;
	int				row;
	t_mlx_global	*mlx_global;

	if (argc < 2)
	{
		ft_putendl_fd("Usage: ./ppm-viewer filename [...]", 2);
		return (-1);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		ft_putstr_fd("Couldn't read file: ", 2);
		ft_putendl_fd(argv[1], 2);
		return (-1);
	}
	if (!validate_metadata(fd, &col, &row))
		return (-1);
	if (!(mlx_global = init_mlx_global(col, row, "PPM Viewer by jleem")))
		return (-1);
	render(mlx_global, fd);
	return (0);
}
