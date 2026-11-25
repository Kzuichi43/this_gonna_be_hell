/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexgonz <alexgonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 11:02:17 by alexgonz          #+#    #+#             */
/*   Updated: 2026/11/25 16:48:02 by alexgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// teto
// picks which sort we use and calls it based on what the disorder is

static t_lector	choose_from_disorder(t_list **a, t_list **b, float disorder)
{
	t_lector	registre;

	if (disorder < 20.00)
		registre = selection_sort(a, b);
	else if (disorder >= 20 && disorder < 50)
		registre = bucket_sort(a, b);
	else
		registre = radix_sort(a, b);
	return (registre);
}

// calls a specific selection sort in the case were not using adaptive

static t_lector	choose_basic(t_list **a,
				t_list **b, t_strategy selected, float value)
{
	t_lector	registre;

	if (selected.strat == 1)
		registre = selection_sort(a, b);
	else if (selected.strat == 2)
		registre = bucket_sort(a, b);
	else if (selected.strat == 3)
		registre = radix_sort(a, b);
	else
		registre = choose_from_disorder(a, b, value);
	return (registre);
}

// does input verification, then calls create_a to initialize the stack then
// picks the selected stratagy finds the disorder value and the given args
// then calls choose_basic, then prints bench if needed

int	push_swap(int argc, char **argv)
{
	t_list		*a;
	float		value;
	t_list		*b;
	t_strategy	selected;
	t_lector	registre;

	b = NULL;
	if (argc < 2)
		return (-1);
	a = ft_create_a(big_brain_list_creator_because_yes(argv, argc));
	if (!a)
		return (-1);
	if (check_valid_input(argc, argv, a) == -1)
		return (error_free_stack(a));
	selected = select_strategy(argc, argv);
	value = disorder_metric(ft_lstsize(a), create_the_array(a));
	if (value == 0)
		return (1);
	registre = choose_basic(&a, &b, selected, value);
	if (selected.bench)
		print_bench(selected, value, registre);
	/*t_list *temp;
	temp = a;
	while (temp)
	{
		printf("%ld, \n", temp->content);
		temp = temp->next;
	}*/
	error_free_stack(a);
	
	return (0);
}

// frees the entire given stack

int	error_free_stack(t_list *a)
{
	t_list	*temp;

	if (!a)
		return (-1);
	temp = a;
	while (a)
	{
		temp = a->next;
		free(a);
		a = temp;
	}
	a = NULL;
	return (-1);
}
