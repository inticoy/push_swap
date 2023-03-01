/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:31:15 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/01 22:19:31 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_order	*set_order(int part, int level);
void	get_section(int size);

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	t_div_info	dinfo;

	if (argc == 1)
		return (0);
	stacks = set_stacks(argc, argv);
	if (!stacks.a)
		raise_error("Error\n");
	dinfo = get_div_info(stacks.num);
	sort_stacks(&stacks, &dinfo);
	return (0);
}
