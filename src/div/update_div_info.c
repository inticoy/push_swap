/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_div_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:39:36 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/03 13:49:06 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	update_div_info(t_div_info *info)
{
	int	i;
	int	old_part;

	info->level--;
	old_part = info->part;
	info->part /= 3;
	i = 0;
	while (i < info->part)
	{
		info->elements[i] = info->elements[i] \
							+ info->elements[(old_part / 3) * 2 - 1 - i] \
							+ info->elements[old_part - 1 - i];
		i++;
	}
}
