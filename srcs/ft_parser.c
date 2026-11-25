/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexgonz <alexgonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 10:06:32 by alexgonz          #+#    #+#             */
/*   Updated: 2026/11/25 18:50:27 by alexgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdlib.h>


static char	*append(char *buffer, char *append)
{
	char	*temp;

	ft_strlcat(buffer, " ", ft_strlen(buffer) + 1);
	ft_printf("buffer: %s\n", buffer);
	temp = ft_strjoin(buffer, append);
	ft_printf("final: %s\n", temp);
	free(append);
	if (!temp)
		return (NULL);
	return (temp);
}
//Checks if a string contains only valid numbers and spaces

int	valid_string(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
			i += 2;
		else if (str[i] >= '0' && str[i] <= '9')
			i++;
		else if (str[i] == ' ')
			i++;
		else
			return (-1);
	}
	return (1);
}

//Create a string and split it containing each entry a number

char	**big_brain_list_creator_because_yes(char **argv, int argc)
{
	int		i;
	char	*final;
	char	**res;

	i = 0;
	while (valid_string(argv[i]) != 1 && argv[i])
		i++;
	final = ft_strdup(argv[i]);
	i++;
	ft_printf("%s\n", final);
	while (i < argc)
	{
		if (ft_check_if_num(argv[i]) == 1 || valid_string(argv[i]) == 1)
		{
			final = append(argv[i], final);
			if (!final)
					return (NULL);
		}
		i++;
	}
	res = ft_split(final, ' ');
	free(final);
	return (res);
}

// adds the given data to a new node and appends that to the list

t_list	*ft_insert_at_last(t_list *last, int data)
{
	t_list	*newnode;

	newnode = malloc(sizeof(t_list));
	if (!newnode)
		return (NULL);
	newnode->content = data;
	if (!last)
	{
		last = newnode;
		last->next = NULL;
	}
	else
	{
		last->next = newnode;
		newnode->next = NULL;
		last = newnode;
	}
	return (last);
}

// makes a node with the content of the first int in the given stack
// goes through all the args, making a new node
// with the given value before moving to the next

t_list	*ft_create_a(char **argv)
{
	t_list	*head;
	t_list	*actual;
	int		i;

	i = 1;
	head = ft_lstnew((long)ft_atoi(argv[0]));
	if (!head)
		return (NULL);
	actual = head;
	while (argv[i])
	{
		actual = ft_insert_at_last(actual, (long)ft_atoi(argv[i]));
		free(argv[i]);
		if (!actual)
		{
			error_free_stack(head);
			return (NULL);
		}
		i++;
	}
	free(argv);
	return (head);
}
