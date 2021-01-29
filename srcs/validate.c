/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 07:54:53 by jleem             #+#    #+#             */
/*   Updated: 2021/01/29 08:21:57 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"
#include "libft.h"
#include "get_next_line.h"
#include "util.h"

int		validate_metadata(int fd, int *out_col, int *out_row)
{
	if (!validate_str(fd, "P3"))
	{
		ft_putendl_fd("Not a valid P3 PPM Image!", 2);
		return (0);
	}
	if (!get_col_row(fd, out_col, out_row))
	{
		ft_putendl_fd("Invalid column and row!", 2);
		return (0);
	}
	if (!validate_str(fd, "255"))
	{
		ft_putendl_fd("Max color should be 255!", 2);
		return (0);
	}
	return (1);
}

int		validate_str(int fd, char const *str)
{
	char			*line;
	int				retcode;
	size_t const	len = ft_strlen(str);

	while ((retcode = get_next_line(fd, &line)) > 0)
	{
		if (line[0] != '#')
		{
			if (ft_strlen(line) == len && ft_strncmp(line, str, len) == 0)
			{
				free(line);
				return (1);
			}
			else
			{
				free(line);
				return (0);
			}
		}
		free(line);
	}
	if (retcode == 0)
		free(line);
	return (0);
}

int		get_col_row(int fd, int *out_col, int *out_row)
{
	char	*line;
	char	**split;
	int		retcode;

	while ((retcode = get_next_line(fd, &line)) > 0)
	{
		if (line[0] != '#')
		{
			if (!(split = ft_split(line, ' ')) ||
				!split[0] || !split[1] || split[2])
			{
				ft_split_free(split);
				free(line);
				return (0);
			}
			else
			{
				*out_col = ft_atoi(split[0]);
				*out_row = ft_atoi(split[1]);
				ft_split_free(split);
				free(line);
				return (1);
			}
		}
		free(line);
	}
	if (retcode == 0)
		free(line);
	return (0);
}

