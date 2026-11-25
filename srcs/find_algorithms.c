/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_algorithms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexgonz <alexgonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 12:27:55 by alexgonz          #+#    #+#             */
/*   Updated: 2026/11/25 16:47:01 by alexgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// finds the maximum int in the stack

long int	find_max(t_list **a)
{
	long int		max;
	t_list			*temp;

	if (!a || !(*a))
		return (0);
	max = (*a)->content;
	temp = (*a);
	while (temp)
	{
		if (max < (temp)->content)
			max = (temp)->content;
		temp = temp->next;
	}
	return (max);
}
// finds the minimum int in the stack

long int	find_min(t_list **a)
{
	t_list			*temp;
	long int		min;

	if (!a || !(*a))
		return (0);
	temp = *a;
	min = temp->content;
	while (temp)
	{
		if (min > temp->content)
			min = temp->content;
		temp = temp->next;
	}
	temp = NULL;
	return (min);
}
