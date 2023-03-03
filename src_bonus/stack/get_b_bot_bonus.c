/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_b_bot_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:06:59 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/03 15:10:17 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap_bonus.h"

int	get_b_bot(t_stacks *stacks)
{
	return (*((int *)ft_lstlast(stacks->b)->content));
}
