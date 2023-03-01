/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_div_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:39:36 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/01 21:26:59 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_div_info	update_div_info(t_div_info old)
{
	t_div_info	info;
	int			i;

	info.level = old.level - 1;
	info.part = old.part / 3;
	info.elements = (int *)ft_calloc(info.part, sizeof(int));
	i = 0;
	while (i < info.part)
	{
		info.elements[i] = old.elements[i] \
							+ old.elements[(old.part / 3) * 2 - 1 - i] \
							+ old.elements[old.part - 1 - i];
		i++;
	}
	ft_free_s(old.elements);
	info.orders = old.orders;
	return (info);
}
