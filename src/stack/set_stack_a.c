/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:27:01 by gyoon             #+#    #+#             */
/*   Updated: 2023/02/20 23:34:33 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

static char	*skip_digits(char *str)
{
	if (*str == '-')
		str++;
	while ('0' <= *str && *str <= '9')
		str++;
	return (str);
}

static void	test(t_list **head, char *arg)
{
	t_list	*node;
	int		number;
	char	*str;

	node = ft_lstnew(new_stack_data());
	number = ft_atoi(arg);
	((t_stack_data *)node->content)->number = number;
	str = ft_itoa(number);
	if (!ft_strncmp(arg, str, ft_strlen(str)))
		ft_lstadd_back(head, node);
	else
		ft_lstclear(head, ft_free_s);
	ft_free_s(str);
}

static t_list	*argv_to_nodes(char *arg)
{
	t_list	*head;

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
		test(&head, arg);
		if (!head)
			return (FT_NULL);
		arg = skip_digits(arg);
		if (*arg != ' ' && *arg)
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
		/* if (node == FT_NULL)
		{
			ft_printf("Hello\n");
			ft_lstclear(&head, ft_free_s);
			return (FT_NULL);
		} */
		ft_lstadd_back(&head, node);
		i++;
	}
	return (head);
}
