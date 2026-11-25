/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexgonz <alexgonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 11:10:34 by alexgonz          #+#    #+#             */
/*   Updated: 2026/11/25 16:48:16 by alexgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// checks that the given inputs are all either numbers 
// or correct arguments

int	check_valid_input(int argc, char **argv, t_list *a)
{
	int	i;

	i = 1;
	while (argc > i)
	{
		if (ft_check_if_num(argv[i]) == -1
			&& ft_valid_identifier(argv[i]) == -1
			&& valid_string(argv[i]) == -1)
			return (-1);
		i++;
	}
	return (check_for_repetition(a));
}

// makes sure there are no duplicate elements

int	check_for_repetition(t_list *a)
{
	t_list	*fixed;
	t_list	*moves;

	if (!a)
		return (-1);
	fixed = a;
	moves = a;
	while (fixed->next)
	{
		moves = fixed->next;
		while (moves)
		{
			if (moves->content == fixed->content)
				return (-1);
			moves = moves->next;
		}
		fixed = fixed->next;
	}
	return (1);
}

// if the minimum int in the stack is negative, offset all of 
// by that number * -1 such that we dont have to consider negatives
// for radix sort 

void	set_all_positive(t_list **a)
{
	t_list	*temp;
	long	min;

	if (find_min(a) >= 0)
		return ;
	min = find_min(a);
	temp = *a;
	while (*a)
	{
		//printf("BEFORE: %ld, ", (*a)->content);
		(*a)->content -= min;
		//printf("AFTER: %ld \n", (*a)->content);
		(*a) = (*a)->next;
	}
	*a = temp;
}

// checks that a given string is a number

int	ft_check_if_num(char *str)
{
	size_t	i;

	i = 0;
	if (ft_strlen(str) >= 12)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '-' && i == 0)
			i += 1;
		if (str[i] > '9' || str[i] < '0')
			return (-1);
		i++;
	}
	if ((long)ft_atoi(str) > 2147483647 || (long)ft_atoi(str) < -2147483648)
		return (-1);
	return (1);
}

// checks if a given string is a valid argument

int	ft_valid_identifier(char *str)
{
	if (!ft_strncmp(str, "--simple", ft_strlen(str)))
		return (1);
	else if (!ft_strncmp(str, "--medium", ft_strlen(str)))
		return (1);
	else if (!ft_strncmp(str, "--complex", ft_strlen(str)))
		return (1);
	else if (!ft_strncmp(str, "--adaptative", ft_strlen(str)))
		return (1);
	else if (!ft_strncmp(str, "--bench", ft_strlen(str)))
		return (1);
	else
		return (-1);
}
