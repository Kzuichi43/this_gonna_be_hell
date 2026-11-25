/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexgonz <alexgonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 11:35:13 by alexgonz          #+#    #+#             */
/*   Updated: 2026/11/18 17:49:42 by alexgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// handles selecting the sort based on the given argument

static int	complexity_select(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_strncmp(argv[i], "--simple", 9))
			return (1);
		else if (!ft_strncmp(argv[i], "--medium", 9))
			return (2);
		else if (!ft_strncmp(argv[i], "--complex", 9))
			return (3);
		else if (!ft_strncmp(argv[i], "--adaptative", 13))
			return (0);
		i++;
	}
	return (0);
}

// picks the strategy, accounting for either using adaptive or forced

t_strategy	select_strategy(int argc, char **argv)
{
	t_strategy	return_val;

	return_val.strat = complexity_select(argc, argv);
	check_for_bench(argc, argv, &return_val);
	return (return_val);
}

// checks if we need to print the bench

void	check_for_bench(int argc, char **argv, t_strategy *selected)
{
	int	i;

	i = 1;
	selected->bench = 0;
	while (i < argc)
	{
		if (!ft_strncmp(argv[i], "--bench", 8))
		{
			selected->bench = 1;
			return ;
		}
		i++;
	}
}
