/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iatoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:54:47 by hferraud          #+#    #+#             */
/*   Updated: 2022/11/26 15:40:40 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_isinstr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_iatoi(const char *str, size_t *index)
{
	long long	result;
	int			sign;

	result = 0;
	sign = 1;
	while (ft_isinstr("\t\v\n\f\r ", str[*index]) != -1)
		(*index)++;
	if (str[*index] == '+' || str[*index] == '-')
		if (str[(*index)++] == '-')
			sign = -1;
	while (ft_isdigit(str[*index]))
	{
		result = result * 10 + (str[*index] - '0');
		(*index)++;
	}
	return (result * sign);
}
