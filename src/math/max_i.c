/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_i.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:10:57 by gyoon             #+#    #+#             */
/*   Updated: 2023/02/25 18:20:47 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

int	max_i(int a, int b)
{
	if (a > b)
		return (0);
	else if (a < b)
		return (1);
	else
		return (-1);
}