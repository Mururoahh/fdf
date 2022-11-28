/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iatohex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:28:11 by hferraud          #+#    #+#             */
/*   Updated: 2022/11/26 17:01:48 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

int	ft_count_size(size_t nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		count++;
		nb /= 16;
	}
	return (count);
}
