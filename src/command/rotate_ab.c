/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:13:58 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/01 13:45:40 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	rotate_ab(t_stacks *stacks, t_bool opt)
{
	rotate_a(stacks, ft_false);
	rotate_b(stacks, ft_false);
	if (opt)
		ft_printf("rr\n");
}
