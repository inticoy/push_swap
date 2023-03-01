/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:38:36 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/01 13:38:45 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

int	min_3(int a, int b, int c)
{
	if (a < b)
	{
		if (a < c)
			return (0);
		else
			return (2);
	}
	else
		return (1 + min_i(b, c));
}