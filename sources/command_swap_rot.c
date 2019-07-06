/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap_rot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 19:09:26 by ssoraka           #+#    #+#             */
/*   Updated: 2019/07/06 19:09:27 by ssoraka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

/*
**	команда sa или sb
*/

void	ft_swap_list(t_elem *begin, char stack)
{
	int temp;

	if (!begin)
		return ;
	if (!(begin->next))
		return ;
	temp = begin->value;
	begin->value = begin->next->value;
	begin->next->value = temp;
	if (stack == 'a' || stack == 'b' || stack == 's')
	{
		ft_putchar('s');
		ft_putchar(stack);
		ft_putchar('\n');
	}
}

/*
**	команда ra или rb
*/

void	ft_rotate_list(t_elem **begin, char stack)
{
	if (*begin && (*begin)->next)
		*begin = (*begin)->next;
	if (stack == 'a' || stack == 'b' || stack == 'r')
	{
		ft_putchar('r');
		ft_putchar(stack);
		ft_putchar('\n');
	}
}

/*
**	команда rra или rrb
*/

void	ft_revers_rotate_list(t_elem **begin, char stack)
{
	if (*begin && (*begin)->prev)
		*begin = (*begin)->prev;
	if (stack == 'a' || stack == 'b' || stack == 'r')
	{
		ft_putstr("rr");
		ft_putchar(stack);
		ft_putchar('\n');
	}
}
