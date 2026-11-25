/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexgonz <alexgonz@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 18:20:42 by alexgonz          #+#    #+#             */
/*   Updated: 2026/11/18 17:10:52 by alexgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// calculates the square root of the given lists length

int	calculate_sqrt(t_list **a)
{
	int	sqrt;
	int	len;

	len = ft_lstsize(*a);
	sqrt = 1;
	while (sqrt <= len / 2)
	{
		if (sqrt * sqrt >= len)
			return (sqrt);
		sqrt++;
	}
	return (sqrt);
}

//COMPUTES THE POSITION OF MAX AND RETURNS ITS POSITION

int	count_index(t_list **a, int max)
{
	int		i;
	t_list	*temp;

	temp = *a;
	i = 0;
	while (temp->content != max)
	{
		i++;
		temp = temp->next;
	}
	temp = NULL;
	return (i);
}

// inits everything in a t_bucket_info
// crucialy, bucket size is set to the min number plus the max number 
// divided by the square root of the length, then all that doubbled

static t_bucket_info	index_innit(t_list **a)
{
	t_bucket_info	index;

	index.max = find_max(a);
	index.size_bucket = 2 * ((unsigned int)find_max(a)
			+ (unsigned int)find_min(a)) / calculate_sqrt(a);
	index.min = index.max - index.size_bucket;
	return (index);
}

// sends everything within the given 
// min/max range of index over to the other stack

static void	send_to_bucket(t_list **a, t_list **b,
				t_bucket_info index, t_lector *registre)
{
	size_t	i;
	size_t	len;

	len = ft_lstsize(*a);
	i = 0;
	while (i < len)
	{
		if (index.min <= (*a)->content && index.max >= (*a)->content)
			oper_put(registre, a, b, "pb");
		else
			oper_rot(registre, a, b, "ra");
		i++;
	}
}

// 
//BUCKET SORT: CREATES BUCKETS OF DETERMINATED SIZE AND 
//CHECKS EVERY RANGE, SENDING IT TO THE OTHER STACK TO 
//END UP WITH AN OPTIMIZED SELECTION SORT

t_lector	bucket_sort(t_list **a, t_list **b)
{
	t_bucket_info	index;
	t_lector		registre;

	registre = register_innit();
	index = index_innit(a);
	while (index.min > find_min(a) - index.size_bucket)
	{
		send_to_bucket(a, b, index, &registre);
		while (ft_lstsize(*b) > 0)
		{
			if ((*b)->content == find_max(b))
				oper_put(&registre, a, b, "pa");
			else
			{
				if ((size_t)count_index(b, find_max(b)) > ft_lstsize(*b) / 2)
					oper_r_rot(&registre, a, b, "rrb");
				else
					oper_rot(&registre, a, b, "rb");
			}
		}
		index.max = index.min + 1;
		index.min -= index.size_bucket - 1;
	}
	return (registre);
}
