/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 11:52:13 by ssoraka           #+#    #+#             */
/*   Updated: 2019/07/06 11:52:13 by ssoraka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

/*
**	создание списка-стека из массива чисел
*/

t_elem	*ft_create_lists(int *arr, int argc)
{
	int		i;
	int		vl[3];
	t_elem	*begin;
	t_elem	*tmp;

	vl[0] = ft_find_min_value(arr, argc);
	vl[1] = ft_find_medium_value(arr, argc);
	vl[2] = ft_find_max_value(arr, argc);
	begin = ft_create_elem(arr[0], vl[0], vl[1], vl[2]);
	tmp = begin;
	i = 1;
	while (i < argc)
	{
		if (!tmp || !(tmp->next = ft_create_elem(arr[i], vl[0], vl[1], vl[2])))
		{
			ft_list_del(begin);
			return (NULL);
		}
		tmp->next->prev = tmp;
		tmp = tmp->next;
		i++;
	}
	(tmp != begin) ? tmp->next = begin : 0;
	(tmp != begin) ? begin->prev = tmp : 0;
	return (begin);
}

/*
**	создание одного элемента стека
*/

t_elem	*ft_create_elem(int value, int min_value, int med_value, int max_value)
{
	t_elem *tmp;

	tmp = (t_elem *)ft_memalloc(sizeof(t_elem));
	if (!tmp)
		return (NULL);
	tmp->value = value;
	tmp->min_value = min_value;
	tmp->medium_value = med_value;
	tmp->max_value = max_value;
	return (tmp);
}

/*
**	удаление списка
*/

void	ft_list_del(t_elem *begin)
{
	int		list_count;
	int		i;
	t_elem	*tmp;

	i = 0;
	list_count = ft_count_of_element_in_stack(begin);
	while (i < list_count)
	{
		tmp = begin;
		begin = begin->next;
		tmp->next = NULL;
		free(tmp);
		tmp = NULL;
		i++;
	}
}
