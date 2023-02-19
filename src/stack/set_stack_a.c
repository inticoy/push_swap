/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:27:01 by gyoon             #+#    #+#             */
/*   Updated: 2023/02/19 20:14:04 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*skip_digits(char *str)
{
	while ('0' <= *str && *str <= '9')
		str++;
	return (str);
}

static t_list	*argv_to_nodes(char *arg)
{
	t_list	*head;
	t_list	*node;

	head = 0;
	while (*arg)
	{
		if (*arg == ' ')
		{
			arg++;
			continue ;
		}
		node = ft_lstnew(new_stack_data());
		((t_stack_data *)node->content)->number = ft_atoi(arg);
		ft_lstadd_back(&head, node);
		arg = skip_digits(arg);
	}
	return (head);
}

t_list	*set_stack_a(int argc, char **argv)
{
	int		i;
	t_list	*head;
	t_list	*node;

	i = 1;
	while (i < argc)
	{
		node = argv_to_nodes(argv[i]);
		ft_lstadd_back(&head, node);
		i++;
	}
	return (head);
}
