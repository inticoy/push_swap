/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:31:41 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/03 16:55:00 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	t_div_info	dinfo;
	int			status;

	if (argc == 1)
		return (0);
	stacks = set_stacks(argc, argv);
	if (!stacks.a)
		raise_error("Error\n");
	dinfo = get_div_info(stacks.num);
	status = check_stacks(&stacks);
	ft_lstclear(&stacks.a, ft_free_s);
	ft_lstclear(&stacks.b, ft_free_s);
	ft_free_s(dinfo.elements);
	ft_free_s(dinfo.orders);
	if (status == -1)
		raise_error("Error\n");
	else if (status == 0)
		ft_printf("KO\n");
	else if (status == 1)
		ft_printf("OK\n");
	return (0);
}
