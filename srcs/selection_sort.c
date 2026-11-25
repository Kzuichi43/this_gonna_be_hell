/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexgonz <alexgonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 12:36:12 by alexgonz          #+#    #+#             */
/*   Updated: 2026/11/17 16:21:44 by alexgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// rotates a untill it finds the min then pushes that to b
// at the end pushes everything from b back to a

t_lector	selection_sort(t_list **a, t_list **b)
{
	int			min;
	t_lector	registre;

	registre = register_innit();
	while (ft_lstsize(*a) > 0)
	{
		min = find_min(a);
		if ((*a)->content == find_min(a))
			oper_put(&registre, a, b, "pb");
		else
		{
			if ((size_t)count_index(a, min) > ft_lstsize(*a) / 2)
				oper_r_rot(&registre, a, b, "rra");
			else
				oper_rot(&registre, a, b, "ra");
		}
	}
	while (ft_lstsize(*b) > 0)
		oper_put(&registre, a, b, "pa");
	return (registre);
}
