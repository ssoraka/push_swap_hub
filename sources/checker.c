/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 11:02:33 by ssoraka           #+#    #+#             */
/*   Updated: 2019/07/06 11:02:33 by ssoraka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

/*
**	выполнение команд из списка
*/

void	ft_use_instruction(char **cmd, t_elem **stack_a, t_elem **stack_b)
{
	int i;

	i = 0;
	while (cmd && cmd[i])
	{
		if (ft_strcmp(cmd[i], "sa") == 0 || ft_strcmp(cmd[i], "ss") == 0)
			ft_swap_list(*stack_a, 0);
		if (ft_strcmp(cmd[i], "sb") == 0 || ft_strcmp(cmd[i], "ss") == 0)
			ft_swap_list(*stack_b, 0);
		if (ft_strcmp(cmd[i], "ra") == 0 || ft_strcmp(cmd[i], "rr") == 0)
			ft_rotate_list(stack_a, 0);
		if (ft_strcmp(cmd[i], "rb") == 0 || ft_strcmp(cmd[i], "rr") == 0)
			ft_rotate_list(stack_b, 0);
		if (ft_strcmp(cmd[i], "rrb") == 0 || ft_strcmp(cmd[i], "rrr") == 0)
			ft_revers_rotate_list(stack_b, 0);
		if (ft_strcmp(cmd[i], "rra") == 0 || ft_strcmp(cmd[i], "rrr") == 0)
			ft_revers_rotate_list(stack_a, 0);
		if (ft_strcmp(cmd[i], "pa") == 0)
			ft_push_list(stack_b, stack_a, 0);
		if (ft_strcmp(cmd[i], "pb") == 0)
			ft_push_list(stack_a, stack_b, 0);
		i++;
	}
}

/*
**	проверка валидности команд
*/

int		ft_not_valid_command(char **commands)
{
	while (*commands)
	{
		if (ft_strcmp(*commands, "ra") && ft_strcmp(*commands, "rb") &&
				ft_strcmp(*commands, "sa") && ft_strcmp(*commands, "sb") &&
				ft_strcmp(*commands, "ss") && ft_strcmp(*commands, "pa") &&
				ft_strcmp(*commands, "pb") && ft_strcmp(*commands, "rra") &&
				ft_strcmp(*commands, "rrb") && ft_strcmp(*commands, "rrr") &&
				ft_strcmp(*commands, "rr"))
			return (1);
		(commands)++;
	}
	return (0);
}

/*
**	получение массива команд из прямого ввода
*/

char	**read_command(void)
{
	char	**cmd;
	int		red;
	char	*str;
	char	buf[1001];

	str = NULL;
	while ((red = read(0, buf, 1000)))
	{
		buf[red] = '\0';
		str = ft_strjoin_free(str, buf, 1, 0);
	}
	cmd = ft_strsplit(str, '\n');
	free(str);
	if (cmd && ft_not_valid_command(cmd))
	{
		ft_str_arr_free(&cmd);
		ft_error(0);
	}
	return (cmd);
}

/*
**	checker
*/

int		main(int argc, char **argv)
{
	int		*arr;
	t_elem	*stack_a;
	t_elem	*stack_b;
	char	**cmd;

	if (argc == 1)
		return (0);
	if (!(arr = ft_valid_arr(&argc, argv)))
		ft_error(0);
	cmd = read_command();
	stack_a = ft_create_lists(arr, argc);
	stack_b = NULL;
	free(arr);
	if (!stack_a)
	{
		ft_str_arr_free(&cmd);
		ft_error(0);
	}
	ft_use_instruction(cmd, &stack_a, &stack_b);
	ft_str_arr_free(&cmd);
	(ft_is_sorted(stack_a) && !stack_b) ? ft_putstr("ОК\n") : ft_putstr("KO\n");
	ft_list_del(stack_a);
	ft_list_del(stack_b);
	return (0);
}
