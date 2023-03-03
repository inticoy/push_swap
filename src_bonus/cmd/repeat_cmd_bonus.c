/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_cmd_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:49:58 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/03 14:49:14 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap_bonus.h"

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
