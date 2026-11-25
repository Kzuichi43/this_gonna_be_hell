/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexgonz <alexgonz@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 15:52:26 by alexgonz          #+#    #+#             */
/*   Updated: 2026/11/25 16:48:30 by alexgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//Create list of indeces

static t_radix_info	start_index(t_list **a)
{
	t_radix_info	index;

	set_all_positive(a);
	index.exp = 0;
	index.max = find_max(a);
	return (index);
}

//DECIDES WHICH OPERATION TO TAKE

static void	radik_jelp(t_lector *registre,
				t_list **a, t_list **b, char *str)
{
	if (!ft_strncmp(str, "pb", 2))
		oper_put(registre, a, b, "pb");
	else if (!ft_strncmp(str, "pa", 2))
		oper_put(registre, b, a, "pa");
	else if (!ft_strncmp(str, "ra", 2))
		oper_rot(registre, a, b, "ra");
	else
		oper_rot(registre, b, a, "rb");
}

//CHECKS IF EACH INPUT IS VALID OR NOT DPENDIING ON THE DIGIT

static void	radik_jelper(t_lector *registre,
				t_list **a, t_list **b, t_radix_info index)
{
	int	i;

	i = ft_lstsize(*a);
	while (i > 0)
	{
		if ((((*a)->content / power(index.exp)) % 10 == index.digit))
		{
			if (index.exp % 2 == 0)
				radik_jelp(registre, a, b, "pb");
			else
				radik_jelp(registre, a, b, "pa");
		}
		else
		{
			if (index.exp % 2 == 0)
				radik_jelp(registre, a, b, "ra");
			else
				radik_jelp(registre, a, b, "rb");
		}
		i--;
	}
}

//ITERATES THROUGH THE DIGITS

static void	radik_orderer(t_lector *registre,
				t_list **a, t_list **b, t_radix_info index)
{
	if (index.exp % 2)
		index.digit = 9;
	else
		index.digit = 0;
	while (index.digit <= 9 && index.digit >= 0)
	{
		radik_jelper(registre, a, b, index);
		if (index.exp % 2)
			index.digit--;
		else
			index.digit++;
	}
}

//RADIK_SORT BLEH :3
//OUR MAIN RADIX SORT THAT IS THE BASE AND CORRECTS THE FINAL

t_lector	radix_sort(t_list **a, t_list **b)
{
	t_radix_info	index;
	t_lector		registre;

	index = start_index(a);
	registre = register_innit();
	while (index.exp < num_digits(index.max))
	{
		//printf("ITERACIO %d \n", index.exp);
		radik_orderer(&registre, a, b, index);
		index.exp++;
		if (index.exp != num_digits(index.max))
			swapping(a, b);
	}
	if (index.exp % 2 == 0)
	{
		swapping(a, b);
		return (registre);
	}
	while (ft_lstsize(*b) > 0)
		oper_put(&registre, a, b, "pa");
	return (registre);
}
