/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_b_bot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:06:59 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/02 15:06:26 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	get_b_bot(t_stacks *stacks)
{
	return (*((int *)ft_lstlast(stacks->b)->content));
}
