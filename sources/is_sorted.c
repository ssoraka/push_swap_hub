/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 19:16:10 by ssoraka           #+#    #+#             */
/*   Updated: 2019/07/06 19:16:10 by ssoraka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

/*
**	проеверяем, является ли массив уже отсортированным с первого элемента
*/

int		ft_is_sorted(t_elem *begin)
{
	int first_value;
	int i;

	i = 0;
	if (!begin)
		return (0);
	if (!(begin->next))
		return (1);
	first_value = begin->value;
	while (i == 0 || (begin && first_value != begin->value))
	{
		if (first_value == begin->next->value)
			break ;
		if (begin->value > begin->next->value)
			return (0);
		begin = begin->next;
		i++;
	}
	return (1);
}

/*
**	проеверяем, является ли массив уже отсортированным с каждого элемента
*/

int		ft_need_only_rotate_for_sort(t_elem *begin)
{
	int first_value;
	int round_count;
	int i;

	i = 0;
	first_value = begin->value;
	round_count = -1;
	while (i == 0 || (begin && first_value != begin->value))
	{
		if (ft_is_sorted(begin))
			round_count = i;
		begin = begin->next;
		i++;
	}
	if (round_count < 0)
		return (0);
	if (round_count == 0)
		return (1);
	if (round_count > i / 2)
		round_count = round_count - i;
	if (round_count < 0)
		return (-1);
	return (2);
}
