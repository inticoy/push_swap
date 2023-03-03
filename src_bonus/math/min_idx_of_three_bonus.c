/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_idx_of_three_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:38:36 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/03 15:29:32 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	min_idx_of_three(int a, int b, int c)
{
	if (a < b)
	{
		if (a < c)
			return (0);
		else
			return (2);
	}
	else
		return (1 + min_idx(b, c));
}
