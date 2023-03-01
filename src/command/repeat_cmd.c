/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:49:58 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/01 15:31:44 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	repeat_cmd(	void (*f)(t_stacks *, t_bool), \
					t_stacks *s, t_bool opt, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		f(s, opt);
		i++;
	}
}
