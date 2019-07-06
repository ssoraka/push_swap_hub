/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 11:50:42 by ssoraka           #+#    #+#             */
/*   Updated: 2019/07/06 11:50:43 by ssoraka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

/*
**	вывод стека на печать
*/

void	ft_print_list(t_elem *begin, char stack)
{
	int first_value;
	int i;

	i = 0;
	ft_putstr("_");
	ft_putchar(stack);
	ft_putstr("_\n");
	if (begin == NULL)
	{
		ft_putendl("NULL");
		return ;
	}
	first_value = begin->value;
	while (i == 0 || (begin && first_value != begin->value))
	{
		ft_putnbr(begin->value);
		ft_putchar('\n');
		begin = begin->next;
		i++;
	}
}

void	*ft_error(int errnum)
{
	errnum = 0;
	ft_putstr_fd("Error\n", 2);
	exit(0);
	return (NULL);
}
