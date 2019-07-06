/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_med_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 19:17:41 by ssoraka           #+#    #+#             */
/*   Updated: 2019/07/06 19:17:41 by ssoraka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int		ft_find_min_value(int *arr, int argc)
{
	int min_value;
	int i;

	i = 1;
	min_value = arr[0];
	while (i < argc)
	{
		if (arr[i] < min_value)
			min_value = arr[i];
		i++;
	}
	return (min_value);
}

int		ft_find_max_value(int *arr, int argc)
{
	int max_value;
	int i;

	i = 1;
	max_value = arr[0];
	while (i < argc)
	{
		if (arr[i] > max_value)
			max_value = arr[i];
		i++;
	}
	return (max_value);
}

/*
**	для определения медианы
*/

int		ft_pubble_int_sort(int *argv, int argc)
{
	int		i;
	int		j;
	int		temp;

	j = 0;
	while (j < argc)
	{
		i = 0;
		while (i < argc - 1)
		{
			if (argv[i] > argv[i + 1])
			{
				temp = argv[i + 1];
				argv[i + 1] = argv[i];
				argv[i] = temp;
			}
			i++;
		}
		j++;
	}
	return (0);
}

/*
**	поиск медианы в массиве чисел для первичного упорядочевания стека b
*/

int		ft_find_medium_value(int *arr, int argc)
{
	int *sorted;
	int medium;

	sorted = (int *)malloc(sizeof(int) * argc);
	ft_memcpy((void *)sorted, (void *)arr, sizeof(int) * argc);
	ft_pubble_int_sort(sorted, argc);
	if (argc > 10)
		medium = sorted[argc / 2 + 3];
	else
		medium = sorted[argc / 2];
	free(sorted);
	return (medium);
}
