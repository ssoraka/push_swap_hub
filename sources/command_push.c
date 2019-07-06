/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 19:09:33 by ssoraka           #+#    #+#             */
/*   Updated: 2019/07/06 19:09:33 by ssoraka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

/*
**	команда push.1 изымаем элемент из стека
*/

static t_elem	*ft_cut_elem(t_elem **begin)
{
	t_elem *cut_elem;

	cut_elem = *begin;
	if (*begin == NULL)
		return (NULL);
	if ((*begin)->next == NULL)
	{
		*begin = NULL;
		return (cut_elem);
	}
	if ((*begin)->next->next == *begin)
	{
		*begin = (*begin)->next;
		(*begin)->prev = NULL;
		(*begin)->next = NULL;
	}
	else
	{
		(*begin)->prev->next = (*begin)->next;
		*begin = (*begin)->next;
		(*begin)->prev = cut_elem->prev;
	}
	cut_elem->prev = NULL;
	cut_elem->next = NULL;
	return (cut_elem);
}

/*
**	команда push.2 вставляем элемент в стек
*/

static void		ft_paste_elem(t_elem **begin, t_elem **new)
{
	if (*new == NULL)
		return ;
	if (*begin == NULL)
		*begin = *new;
	else if ((*begin)->next == NULL)
	{
		(*new)->next = *begin;
		(*new)->prev = *begin;
		(*begin)->next = *new;
		(*begin)->prev = *new;
		*begin = (*begin)->prev;
	}
	else
	{
		(*new)->next = *begin;
		(*new)->prev = (*begin)->prev;
		(*begin)->prev = *new;
		(*new)->prev->next = *new;
		*begin = (*begin)->prev;
	}
	*new = NULL;
}

/*
**	команда push
*/

void			ft_push_list(t_elem **stack_a, t_elem **stack_b, char stack)
{
	t_elem *cut_list;

	if (*stack_a == NULL)
		return ;
	cut_list = ft_cut_elem(stack_a);
	ft_paste_elem(stack_b, &cut_list);
	if (stack == 'a' || stack == 'b')
	{
		ft_putchar('p');
		ft_putchar(stack);
		ft_putchar('\n');
	}
}
