/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_idx_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:28:49 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/03 15:08:12 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	min_idx(int a, int b)
{
	if (a < b)
		return (0);
	else if (a > b)
		return (1);
	else
		return (-1);
}
