/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:04:27 by hferraud          #+#    #+#             */
/*   Updated: 2022/12/13 04:44:59 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H

# define FT_UTILS_H

# include "fdf.h"

int			ft_isdigit(char c);
int			ft_iatoi(const char *str, size_t *index);
void		ft_bzero(void *ptr, size_t size);

#endif
