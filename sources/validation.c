/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 11:48:26 by ssoraka           #+#    #+#             */
/*   Updated: 2019/07/06 11:48:27 by ssoraka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

/*
**	проверка наличия лишних символов в строке и
*/

int		ft_is_not_number(char **str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (**str == '0' && (*str + 1) && ft_isdigit(*(*str + 1)))
		(*str)++;
	tmp = *str;
	if (!ft_isdigit(*tmp))
		return (1);
	while (*tmp && ft_isdigit(*tmp))
		tmp++;
	i = ft_strlen(tmp);
	while (i > 0)
	{
		if (ft_isspace(tmp[i - 1]))
			tmp[i - 1] = '\0';
		else
			break ;
		i--;
	}
	if (*tmp)
		return (1);
	return (0);
}

/*
**	проверка наличия лишних символов в строке и
**	принадлежности числа к integer
*/

int		ft_str_not_int_number(char *str)
{
	int i;
	int minus;

	i = 0;
	minus = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		minus = 1;
	if (*str == '-' || *str == '+')
		str++;
	if (ft_is_not_number(&str))
		return (1);
	if (ft_strlen(str) > 10)
		return (1);
	if (ft_strlen(str) == 10)
	{
		if (minus && ft_strcmp("2147483648", str) < 0)
			return (1);
		if (!minus && ft_strcmp("2147483647", str) < 0)
			return (1);
	}
	return (0);
}

/*
**	получение массива чисел из массива строк
*/

int		*ft_arr_int_from_str(char **argv, int argc)
{
	int *arr;
	int i;

	i = 0;
	while (i < argc)
	{
		if (ft_str_not_int_number(argv[i]))
			return (NULL);
		i++;
	}
	if (!(arr = (int *)malloc(4 * (argc))))
		return (NULL);
	i = 0;
	while (i < argc)
	{
		arr[i] = ft_atoi(argv[i]);
		i++;
	}
	return (arr);
}

/*
**	проверка на повторяющиеся числа в массиве
*/

int		ft_dont_have_repeats_num(int *arr, int argc)
{
	int i;
	int j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		while (j < i)
		{
			if (arr[i] == arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/*
**	проверка валидности массива строк и строки с элементами,
**	получение массива чисел
*/

int		*ft_valid_arr(int *argc, char **argv)
{
	int *arr;
	int create_argv;

	create_argv = 0;
	argv++;
	if (*argc == 2)
	{
		argv = ft_strsplit(*argv, ' ');
		*argc = 0;
		create_argv = TRUE;
		while (argv[*argc])
			(*argc)++;
	}
	else
		(*argc)--;
	arr = ft_arr_int_from_str(argv, *argc);
	if (create_argv)
		ft_str_arr_free(&argv);
	if (arr && ft_dont_have_repeats_num(arr, *argc))
		return (arr);
	free(arr);
	ft_error(0);
	return (NULL);
}
