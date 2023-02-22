/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:54:29 by gyoon             #+#    #+#             */
/*   Updated: 2023/02/22 17:33:52 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_section(int size)
{
	int	div;
	int	r;
	int	q;

	div = 3;
	while (size / div >= 6)
	{
		div *= 3;
	}
	q = size / div;
	r = size % div;
	for (int i = 0; i < div - r; i++)
		ft_printf("%d ", q);
	ft_printf("\n");
	for (int i = 0; i < r; i++)
	 	ft_printf("%d ", q+1);
}

void	sort_stacks(t_stacks stacks)
{
	int	total;

	total = ft_lstsize(stacks.a);

}
