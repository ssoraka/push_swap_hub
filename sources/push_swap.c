/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 11:13:07 by ssoraka           #+#    #+#             */
/*   Updated: 2019/05/27 11:13:07 by ssoraka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

/*
**	финт, определяем длинную последовательность в стеке,
**	которая стоит по порядку (ищем числа по возрастанию с разбросом значений
**	менее (max_value - min_value) * 6%)
*/

int		ft_is_num_are_sorted(t_elem *begin)
{
	int value;
	int sorted;
	int delta;

	value = begin->value;
	sorted = begin->min_value;
	delta = ((begin->max_value - begin->min_value) / 100) * 6;
	if (delta < 10)
		delta = 10;
	while (begin->value != sorted)
		begin = begin->next;
	while (begin->value != value)
	{
		if (sorted < begin->value && sorted > (begin->value - delta))
			sorted = begin->value;
		begin = begin->next;
	}
	if (sorted <= begin->value && sorted > (begin->value - delta))
		return (1);
	return (0);
}

/*
**	сортировка вставками.первая 2: возвращение элементов в стеке
**	в оптимальной последовательности
*/

void	ft_return_from_b_to_a(t_elem **stack_a, t_elem **stack_b)
{
	int rotations_ab;
	int rotations_a;

	rotations_ab = ft_min_count_of_rotation_stacks(*stack_a, *stack_b);
	rotations_a = ft_min_count_of_rotat_for_insert(*stack_a, (*stack_b)->value);
	if (rotations_ab == RR)
	{
		ft_rotate_list(stack_b, 'r');
		ft_rotate_list(stack_a, 0);
	}
	else if (rotations_ab == RRR)
	{
		ft_revers_rotate_list(stack_b, 'r');
		ft_revers_rotate_list(stack_a, 0);
	}
	else if (rotations_ab == RB)
		ft_rotate_list(stack_b, 'b');
	else if (rotations_ab == RRB)
		ft_revers_rotate_list(stack_b, 'b');
	else if (rotations_a > 0)
		ft_rotate_list(stack_a, 'a');
	else if (rotations_a < 0)
		ft_revers_rotate_list(stack_a, 'a');
	else if (rotations_a == 0)
		ft_push_list(stack_b, stack_a, 'a');
}

/*
**	сортировка вставками.первая часть: избавление от лишних элементов в стеке
*/

void	ft_push_notsorted_element_to_b(t_elem **stack_a, t_elem **stack_b,
int count_a)
{
	if ((*stack_a)->value == (*stack_a)->min_value ||
	ft_is_num_are_sorted(*stack_a))
	{
		if (count_a <= 5 && (*stack_a)->next->value != (*stack_a)->min_value &&
		(*stack_a)->next->value < (*stack_a)->value &&
		(*stack_a)->next->value > (*stack_a)->prev->value)
			ft_swap_list(*stack_a, 'a');
		else
			ft_rotate_list(stack_a, 'a');
	}
	else
	{
		ft_push_list(stack_a, stack_b, 'b');
		if (count_a > 5 && (*stack_b)->value < (*stack_a)->medium_value &&
		ft_count_of_element_in_stack(*stack_b) > 1)
			ft_rotate_list(stack_b, 'b');
	}
}

/*
**	сортировка вставками
*/

t_elem	*ft_vstavka_sort(t_elem *stack_a, t_elem *stack_b)
{
	int count_a;

	count_a = ft_count_of_element_in_stack(stack_a);
	while (stack_a && ft_need_only_rotate_for_sort(stack_a) == 0)
		ft_push_notsorted_element_to_b(&stack_a, &stack_b, count_a);
	while (stack_b)
		ft_return_from_b_to_a(&stack_a, &stack_b);
	while (stack_a->value != stack_a->min_value)
	{
		if (ft_need_only_rotate_for_sort(stack_a) > 0)
			ft_rotate_list(&stack_a, 'a');
		else if (ft_need_only_rotate_for_sort(stack_a) < 0)
			ft_revers_rotate_list(&stack_a, 'a');
	}
	return (stack_a);
}

/*
**	push-swap
*/

int		main(int argc, char **argv)
{
	int		*arr;
	t_elem	*stack_a;
	t_elem	*stack_b;

	if (argc == 1)
		return (0);
	if (!(arr = ft_valid_arr(&argc, argv)))
		ft_error(0);
	stack_a = ft_create_lists(arr, argc);
	stack_b = NULL;
	free(arr);
	if (!stack_a)
		ft_error(0);
	stack_a = ft_vstavka_sort(stack_a, stack_b);
	ft_list_del(stack_a);
	ft_list_del(stack_b);
	return (0);
}
