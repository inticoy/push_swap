/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:31:15 by gyoon             #+#    #+#             */
/*   Updated: 2023/02/20 23:26:59 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc == 1)
		return (0);
	stacks = set_stacks(argc, argv);
	if (!stacks.a || !stacks.b)
		raise_error("Error\n");
	print_stacks(stacks);
	print_stacks(stacks);
	return (0);
}
