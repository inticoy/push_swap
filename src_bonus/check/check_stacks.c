/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:58:49 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/03 16:53:01 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap_bonus.h"
#include <unistd.h>

static int	get_cmd_idx(char *cmd)
{
	if (!ft_strncmp(cmd, "pa", 2))
		return (0);
	else if (!ft_strncmp(cmd, "pb", 2))
		return (1);
	else if (!ft_strncmp(cmd, "rra", 3))
		return (2);
	else if (!ft_strncmp(cmd, "rrr", 3))
		return (3);
	else if (!ft_strncmp(cmd, "rrb", 3))
		return (4);
	else if (!ft_strncmp(cmd, "ra", 2))
		return (5);
	else if (!ft_strncmp(cmd, "rr", 2))
		return (6);
	else if (!ft_strncmp(cmd, "rb", 2))
		return (7);
	else if (!ft_strncmp(cmd, "sa", 2))
		return (8);
	else if (!ft_strncmp(cmd, "ss", 2))
		return (9);
	else if (!ft_strncmp(cmd, "sb", 2))
		return (10);
	else
		return (-1);
}

static void	execute_cmd(t_stacks *stacks, int cmd_idx)
{
	if (cmd_idx == 0)
		push_a(stacks, ft_false);
	else if (cmd_idx == 1)
		push_b(stacks, ft_false);
	else if (cmd_idx == 2)
		rev_rotate_a(stacks, ft_false);
	else if (cmd_idx == 3)
		rev_rotate_ab(stacks, ft_false);
	else if (cmd_idx == 4)
		rev_rotate_b(stacks, ft_false);
	else if (cmd_idx == 5)
		rotate_a(stacks, ft_false);
	else if (cmd_idx == 6)
		rotate_ab(stacks, ft_false);
	else if (cmd_idx == 7)
		rotate_b(stacks, ft_false);
	else if (cmd_idx == 8)
		swap_a(stacks, ft_false);
	else if (cmd_idx == 9)
		swap_ab(stacks, ft_false);
	else if (cmd_idx == 10)
		swap_b(stacks, ft_false);
}

int	check_stacks(t_stacks *stacks)
{
	char	*cmd;
	int		cmd_idx;

	while (1)
	{
		cmd = get_next_line(STDIN);
		if (!cmd)
			break ;
		cmd_idx = get_cmd_idx(cmd);
		if (cmd_idx < 0)
		{
			ft_free_s(cmd);
			return (-1);
		}
		execute_cmd(stacks, cmd_idx);
		ft_free_s(cmd);
		cmd = FT_NULL;
	}
	if (is_sorted(stacks) && !stacks->b)
		return (1);
	else
		return (0);
}
