/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:27:01 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/02 13:56:51 by gyoon            ###   ########.fr       */
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

static void	add_node(t_list **head, char *arg)
{
	int		*content;
	int		number;
	char	*str;
	t_list	*node;

	content = (int *)ft_calloc(1, sizeof(int));
	if (!content)
		ft_lstclear(head, ft_free_s);
	number = ft_atoi(arg);
	*content = number;
	node = ft_lstnew(content);
	str = ft_itoa(number);
	if (!str)
		ft_lstclear(head, ft_free_s);
	else if (!ft_strncmp(arg, str, ft_strlen(str)))
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
		add_node(&head, arg);
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

t_list	*set_stack(int argc, char **argv)
{
	int		i;
	t_list	*head;
	t_list	*node;

	head = FT_NULL;
	i = 1;
	while (i < argc)
	{
		node = argv_to_nodes(argv[i]);
		if (!node)
		{
			ft_lstclear(&head, ft_free_s);
			return (FT_NULL);
		}
		ft_lstadd_back(&head, node);
		i++;
	}
	return (head);
}
