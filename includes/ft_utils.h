/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:04:27 by hferraud          #+#    #+#             */
/*   Updated: 2022/12/09 18:29:27 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H

# define FT_UTILS_H

typedef struct s_map_line
{
	char				*line;
	struct s_map_line	*next;
}						t_map_line;

# include "fdf.h"

t_map_line	*map_to_list(char *filename);
size_t		lstrev(t_map_line **head);
int			ft_iatoi(const char *str, size_t *index);
int			ft_isdigit(char c);

#endif
