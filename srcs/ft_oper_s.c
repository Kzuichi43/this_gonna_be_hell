/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oper_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdyboski <zdyboski@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 15:23:10 by zdyboski          #+#    #+#             */
/*   Updated: 2026/11/18 18:53:00 by alexgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// swaps the first two elements of a given stack

static int	swap(t_list *stack)
{
	int	tmp;	

	if (ft_lstsize(stack) < 2)
		return (-1);
	tmp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = tmp;
	return (1);
}

// swaps a and prints it

int	sa(t_list *stack)
{
	if (swap(stack) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (1);
}

// swaps b and prints it

int	sb(t_list *stack)
{
	if (swap(stack) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	return (1);
}

// swaps both and prints it

int	ss(t_list *a_stack, t_list *b_stack)
{
	if (swap(a_stack) == -1 && swap(b_stack) == -1)
		return (-1);
	ft_putendl_fd("ss", 1);
	return (1);
}
