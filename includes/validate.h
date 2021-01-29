/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 07:51:43 by jleem             #+#    #+#             */
/*   Updated: 2021/01/29 07:58:56 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_H
# define VALIDATE_H

int		validate_metadata(int fd, int *out_col, int *out_row);
int		validate_str(int fd, char const *str);
int		get_col_row(int fd, int *out_col, int *out_row);

#endif
