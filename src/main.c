/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:31:15 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/02 14:02:19 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_lstclear(&stacks.a, ft_free_s);
	ft_lstclear(&stacks.b, ft_free_s);
	ft_free_s(dinfo.elements);
	ft_free_s(dinfo.orders);
	return (0);
}
