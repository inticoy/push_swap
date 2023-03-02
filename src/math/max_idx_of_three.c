/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_idx_of_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:37:56 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/02 22:52:38 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

int	max_idx_of_three(int a, int b, int c)
{
	if (a > b)
	{
		if (a > c)
			return (0);
		else
			return (2);
	}
	else
		return (1 + max_i(b, c));
}
