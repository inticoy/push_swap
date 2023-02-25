/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:12:34 by gyoon             #+#    #+#             */
/*   Updated: 2023/02/25 21:34:33 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_stacks	init_stacks(void)
{
	t_stacks	stacks;

	stacks.num = 0;
	stacks.a = FT_NULL;
	stacks.b = FT_NULL;
	return (stacks);
}
