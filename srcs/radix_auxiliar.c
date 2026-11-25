/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_auxiliar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexgonz <alexgonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 17:30:32 by alexgonz          #+#    #+#             */
/*   Updated: 2026/11/25 16:25:17 by alexgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// calculates the power to 10 of a given number, ie passing 5 in here is
// the same as doing 10 ^ 5

int	power(int i)
{
	int	result;

	result = 1;
	if (i == 0)
		return (result);
	while (i > 0)
	{
		result *= 10;
		i--;
	}
	return (result);
}

// calculates how many digits a given int has

int	num_digits(long max)
{
	int	i;

	i = 1;
	while (max >= 10)
	{
		max /= 10;
		i++;
	}
	return (i);
}

// swaps the two lists, so a will point to be and b to a
void	swapping(t_list **a, t_list **b)
{
	t_list	*temp;

	temp = (*a);
	*a = (*b);
	*b = temp;
}
