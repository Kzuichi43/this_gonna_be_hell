/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oper_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdyboski <zdyboski@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 15:23:10 by zdyboski          #+#    #+#             */
/*   Updated: 2026/11/18 09:03:44 by alexgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// rotates the stack in reverse, last becomes first

static void	rrot(t_list **stack)
{
	t_list	*head;
	t_list	*first;
	t_list	*temp;
	int		len;
	int		i;

	if (ft_lstsize(*stack) < 2)
		return ;
	i = 0;
	first = *stack;
	temp = *stack;
	len = ft_lstsize(*stack);
	while (i < (len - 2))
	{
		temp = temp->next;
		i++;
	}
	temp->next->next = first;
	head = temp->next;
	temp->next = NULL;
	*stack = head;
}

// reverse rotates stack a and prints it

void	rra(t_list **stack)
{
	rrot(stack);
	ft_putendl_fd("rra", 1);
}

// reverse rotates stack a and prints it

void	rrb(t_list **stack)
{
	rrot(stack);
	ft_putendl_fd("rrb", 1);
}

// reverse rotates both stacks and prints it

void	rrr(t_list **a_stack, t_list **b_stack)
{
	rrot(a_stack);
	rrot(b_stack);
	ft_putendl_fd("rrr", 1);
}
