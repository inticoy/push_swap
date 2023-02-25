/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:31:15 by gyoon             #+#    #+#             */
/*   Updated: 2023/02/25 15:05:11 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_order	*set_order(int part, int level);
void	get_section(int size);

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc == 1)
		return (0);
	stacks = set_stacks(argc, argv);
	if (!stacks.a)
		raise_error("Error\n");
	sort_stacks(&stacks);
	return (0);
}
