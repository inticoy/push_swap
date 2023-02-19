/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_argument.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:49:29 by gyoon             #+#    #+#             */
/*   Updated: 2023/02/19 20:24:28 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	validate_argument(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		while (*argv[i])
		{
			/* if (('0' <= *argv[i] && *argv[i] <= '9') || *argv[i] == ' ')
				return (ft_false); */
			argv[i]++;
		}
		i++;
	}
	return (ft_true);
}
