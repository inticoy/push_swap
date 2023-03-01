/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_ab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:17:41 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/01 13:43:52 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	rev_rotate_ab(t_stacks *stacks, t_bool opt)
{
	rev_rotate_a(stacks, ft_false);
	rev_rotate_b(stacks, ft_false);
	if (opt)
		ft_printf("rrr\n");
}
