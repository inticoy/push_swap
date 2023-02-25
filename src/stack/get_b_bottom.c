/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_b_bottom.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:06:59 by gyoon             #+#    #+#             */
/*   Updated: 2023/02/25 18:17:41 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	get_b_bottom(t_stacks *stacks)
{
	return (*((int *)ft_lstlast(stacks->b)->content));
}
