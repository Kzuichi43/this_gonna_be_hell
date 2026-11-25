/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexgonz <alexgonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 18:58:17 by alexgonz          #+#    #+#             */
/*   Updated: 2026/11/18 18:58:57 by alexgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//CREATES AN ARRAY WITH THE ELEMENTS OF A IN ORDER
//TO BE ABLE TO CALCULATE EASILY THE DISORDER

int	*create_the_array(t_list *a)
{
	int		*arr;
	int		i;
	t_list	*temp;

	i = 0;
	if (!a || ft_lstsize(a) < 1)
		return (NULL);
	arr = malloc(sizeof(int) * (ft_lstsize(a) + 1));
	if (!arr)
		return (NULL);
	temp = a;
	while (temp)
	{
		arr[i] = temp->content;
		temp = temp->next;
		i++;
	}
	temp = NULL;
	return (arr);
}

// function to calculate the disorder as given by the subject pdf

float	disorder_metric(size_t len, int *arr)
{
	size_t	i;
	size_t	j;
	int		mistakes;
	int		total_pairs;

	i = 0;
	mistakes = 0;
	total_pairs = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			total_pairs++;
			if (arr[i] > arr[j])
				mistakes++;
			j++;
		}
		i++;
	}
	free(arr);
	return (((float)mistakes / (float)total_pairs) * 100);
}
