/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ab_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:13:58 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/03 14:49:26 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap_bonus.h"

void	rotate_ab(t_stacks *stacks, t_bool opt)
{
	rotate_a(stacks, ft_false);
	rotate_b(stacks, ft_false);
	if (opt)
		ft_printf("rr\n");
}
