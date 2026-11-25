/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexgonz <alexgonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 15:52:00 by alexgonz          #+#    #+#             */
/*   Updated: 2026/11/18 08:58:23 by alexgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	ft_putchar_fd(c, 2);
	return (1);
}

int	print_str(char *str)
{
	if (!str)
		return (write(2, "(null)", 6));
	else
		return (write(2, str, ft_strlen(str)));
}
