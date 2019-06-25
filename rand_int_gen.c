/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand_int_gen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 12:23:19 by ssoraka           #+#    #+#             */
/*   Updated: 2019/06/25 12:23:19 by ssoraka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <time.h>

int *ft_uniq_int_gen(int argc)
{
	int *arr;
	int i;
	int j;
	int num;

	i = 0;
	arr = (int *)ft_memalloc(4 * argc);

	srand(time (NULL));
	while (i < argc)
	{
		num = rand() - RAND_MAX / 2;
		j = 0;
		while (j < i)
		{
			if (num == arr[i])
				num = arr[0];
			j++;
		}
		if (num != arr[0])
		{
			arr[i] = num;
			i++;
		}
	}
	return (arr);
}


int		main(int argc, char **argv)
{
	int *mass;
	if (argc == 1)
		argc = 10;
	else
		argc = ft_atoi(argv[1]);
	mass = ft_uniq_int_gen(argc);

	int i = 0;
	while (i < argc)
	{
		printf("%d\n", mass[i]);
		i++;
	}
	free(mass);

	return (0);
}
