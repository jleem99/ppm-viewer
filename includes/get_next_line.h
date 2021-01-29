/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@students.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 09:49:47 by jleem             #+#    #+#             */
/*   Updated: 2021/01/01 08:21:55 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX _SC_OPEN_MAX
# endif

typedef struct	s_linestack
{
	char	*str;
	size_t	strlen;
	size_t	lines;
	char	is_eof;
}				t_linestack;

int				get_next_line(int fd, char **line);

char			*ft_linestack_pop(t_linestack *stack);
int				ft_parse_read(t_linestack *stack,
								char const *buf,
								size_t bytesread);

#endif
