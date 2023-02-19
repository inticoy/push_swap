/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:12:34 by gyoon             #+#    #+#             */
/*   Updated: 2023/02/19 16:14:06 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_stacks	init_stacks(void)
{
	t_stacks	stacks;

	stacks.a = FT_NULL;
	stacks.b = FT_NULL;
	return (stacks);
}
