/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:27:01 by gyoon             #+#    #+#             */
/*   Updated: 2023/02/20 17:30:03 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

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

	if (!*arg)
		return (FT_NULL);
	head = FT_NULL;
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
		if (*arg != ' ' || !*arg)
		{
			ft_lstclear(&head, ft_free_s);
			return (FT_NULL);
		}
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
		if (!node)
			// do sth
		ft_lstadd_back(&head, node);
		i++;
	}
	return (head);
}
