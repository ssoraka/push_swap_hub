/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 18:37:16 by ssoraka           #+#    #+#             */
/*   Updated: 2019/07/06 18:37:16 by ssoraka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

/*
**	определяем количество элементов в стеке
*/

int		ft_count_of_element_in_stack(t_elem *begin)
{
	int count;
	int first_value;

	count = 0;
	if (begin == NULL)
		return (0);
	first_value = begin->value;
	while (count == 0 || (begin && first_value != begin->value))
	{
		begin = begin->next;
		count++;
	}
	return (count);
}

/*
**	определяем число поворотов стека для установки выбраного числа в начало
*/

int		ft_min_count_of_rotation(t_elem *begin, int value)
{
	int round_count;
	int list_count;

	round_count = 0;
	if (begin == NULL)
		return (0);
	if (begin->next == NULL)
		return (0);
	list_count = ft_count_of_element_in_stack(begin);
	while (round_count < list_count)
	{
		if (value == begin->value)
			break ;
		begin = begin->next;
		round_count++;
	}
	if (round_count > list_count / 2)
		round_count = round_count - list_count;
	return (round_count);
}

/*
**	определяем число поворотов стека необходимого для вставки
*/

int		ft_min_count_of_rotat_for_insert(t_elem *begin, int value)
{
	int round_count;
	int list_count;

	round_count = 0;
	list_count = ft_count_of_element_in_stack(begin);
	while (round_count < list_count)
	{
		if (begin->next == NULL)
			break ;
		if (value < begin->value && value > begin->prev->value)
			break ;
		if (value > begin->prev->value && begin->value == begin->min_value)
			break ;
		begin = begin->next;
		round_count++;
	}
	if (round_count > list_count / 2)
		round_count = round_count - list_count;
	return (round_count);
}

/*
**	определяем наименьшую комбинацию поворотов стеков для вставки
*/

int		ft_min_count_of_rotation_stacks(t_elem *stack_a, t_elem *stack_b)
{
	int		list_countb;
	int		rotate[3];
	int		min_values[3];
	t_elem	*begin_of_b;

	begin_of_b = stack_b;
	list_countb = ft_count_of_element_in_stack(stack_b);
	min_values[2] = 2147483646;
	while (stack_b && list_countb > 0)
	{
		rotate[0] = ft_min_count_of_rotation(begin_of_b, stack_b->value);
		rotate[1] = ft_min_count_of_rotat_for_insert(stack_a, stack_b->value);
		if (ft_znak(rotate[0]) == ft_znak(rotate[1]))
			rotate[2] = ft_max(ft_abs(rotate[0]), ft_abs(rotate[1]));
		else
			rotate[2] = ft_abs(rotate[0]) + ft_abs(rotate[1]);
		if (rotate[2] < min_values[2])
			ft_memcpy((void *)min_values, (void *)rotate, 12);
		stack_b = stack_b->next;
		list_countb--;
	}
	if (ft_znak(min_values[0]) == ft_znak(min_values[0]))
		return (ft_znak(min_values[0]) + ft_znak(min_values[0]));
	return (ft_znak(min_values[0]));
}
