/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:22:58 by hferraud          #+#    #+#             */
/*   Updated: 2022/12/13 04:45:25 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "fdf.h"

typedef struct s_map_line
{
	char				*line;
	struct s_map_line	*next;
}						t_map_line;

t_map		parse_map(char *filename);
t_map_line	*map_to_list(char *filename);
size_t		lstrev(t_map_line **head);

#endif
