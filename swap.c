/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 11:13:07 by ssoraka           #+#    #+#             */
/*   Updated: 2019/05/27 11:13:07 by ssoraka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <time.h>


#define SUCCESS 0
#define FAIL 1
#define ERROR -1

#define TEST1


void	ft_print_arr(int argc, int *argv)
{
	int		i;

	i = 0;
	while (i < argc)
	{
		printf("%d\n", argv[i]);
		i++;
	}
}


void	ft_swap(int *a, int *b)
{
	int temp;

	if (!a || !b)
		return ;
	temp = *a;
	*a = *b;
	*b = temp;
}


int ft_next_argc(int i, int argc)
{
	i++;
	if (i >= argc)
		i = 0;
	return (i);
}


int ft_prev_argc(int i, int argc)
{
	i--;
	if (i < 0)
		i = argc - 1;
	return (i);
}

/*
int ft_is_sorted(int *argv, int i, int argc)
{
	int		n;

	n = 0;
	while (n < argc - 1)
	{
		if (argv[i] > argv[ft_next_argc(i, argc)])
			return (0);
		i = ft_next_argc(i, argc);
		n++;
	}
	return (1);
}
*/

void ft_next_argv(int *argv, int argc)
{
	int i;
	int temp;

	temp = argv[0];
	i = 0;
	while (i < argc - 1)
	{
		argv[i] = argv[i + 1];
		i++;
	}
	argv[i] = temp;
}

void ft_prev_argv(int *argv, int argc)
{
	int i;
	int temp;

	temp = argv[argc - 1];
	i = argc - 1;
	while (i > 0)
	{
		argv[i] = argv[i - 1];
		i--;
	}
	argv[0] = temp;
}


/*
void	ft_sort_argv(int argc, int *argv)
{
	int		i;
	int		action;
	int		*active;
	int		*next;
	int		*prev;

	int		j = 0;

	action = 0;
	i = 0;
	while (j < 1000)
	{
		active = &(argv[i]);
		next = &(argv[ft_next_argc(i, argc)]);
		prev = &(argv[ft_prev_argc(i, argc)]);

		if (*active > *next && i != argc - 1)
		{
			ft_swap(active, next);
			action++;
		}

		if (ft_is_sorted(argv, i, argc))
			break ;
		if (*active < *prev && i != 0)
			i = ft_prev_argc(i, argc);
		else
			i = ft_next_argc(i, argc);

		action++;
		j++;
	}
	printf("\n%d\n", action);
}
*/



/*
int check(int *tab, int min, int len)
{
    int i;

    i = 0;
    while (tab[i] != min)
        i++;
    i++;
    if (i >= len)
        i = i - len;
    if (i == 0)
        i++;
    while (tab[i - 1] < tab[i])
    {

        i++;
        if (i >= len)
            i = i - len;
    }
    if (tab[i] == min)
        return (len - i);
    return (0);
}
*/



/*
int        main222()
{
    //int tab[10] = {5, 56, 3, 45, 30, -4, 18, -100, 0, 13};
    //int tab[4] = {7, 3, 5 ,1};
    int tab[6] = {8, 5, 3, 4, 2, 1};
    //int tab[] = {10,3,4,5,9,13,0,6,78,8};
    //int tab[] = {3,2,0};
    int i;
    int len = 6;
    int t;
    int j;
    int count;

    i = 1;
    count = 0;
    while (!check(tab, 1, len))
    {
        t = tab[i];
        count++;
        j = i - 1;
        while (j >= 0 && tab[j] > t)
        {
            tab[j + 1] = tab[j];
            j--;
            count++;
        }
        tab[j + 1] = t;
        i++;
        if (i >= len)
            i = i - len;
    }
    printf(“%d\n”, count + check(tab, 1, len));
    i = 0;
    while (i < len)
    {
        printf(“%d\t”, tab[i]);
        i++;
    }
}*/

/*
int		main(int argc, char **argv)
{
	int arr[] = {10,3,4,5,9,13,0,6,78,8};
	t_arr *arra = 0;
	int *arrb = 0;

	arra = arr;
	int count = 10;
	int min = 0;


	ft_sa();
	ft_sb();
	ft_ss();



	ft_print_arr(count, arr);
	//ft_sort_argv(count, arr);
	printf("\n");
	ft_prev_argv(arr, count);
	ft_print_arr(count, arr);

	printf("\n");
	ft_prev_argv(arr, count);
	ft_print_arr(count, arr);

	printf("\n");
	ft_prev_argv(arr, count);
	ft_print_arr(count, arr);

	return (0);
}
*/

typedef struct		s_arr
{
	int				*arr;
	int				count;
	int				first_elem;
	int				min_elem;
	int				max_elem;
}					t_arr;


typedef struct		s_elem
{
	int				value;
	int				number;
	int				min_value;
	struct s_elem	*next;
	struct s_elem	*prev;
	struct s_arr	*arr;
}					t_elem;


t_elem	*ft_create_elem(int value, int min_value)
{
	t_elem *tmp;

	tmp = (t_elem *)ft_memalloc(sizeof(t_elem));
	tmp->value = value;
	tmp->min_value = min_value;
	return (tmp);
}


int ft_find_min_value(int *arr, int argc)
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
	return(min_value);
}



t_elem	*ft_create_lists(int *arr, int argc)
{
	int i;
	int min_value;
	t_elem *begin;
	t_elem *tmp;

	if (!argc)
		return (NULL);
	min_value = ft_find_min_value(arr, argc);
	begin = ft_create_elem(arr[0], min_value);
	tmp = begin;
	i = 1;
	while (i < argc)
	{
		tmp->next = ft_create_elem(arr[i], min_value);
		tmp->next->prev = tmp;
		tmp = tmp->next;
		i++;
	}
	tmp->next = begin;
	begin->prev = tmp;
	return (begin);
}


void ft_print_list(t_elem *begin)
{
	int first_value;
	int i;

	i = 0;
	if (begin == NULL)
	{
		printf("NULL\n");
		return ;
	}
	first_value = begin->value;
	while (i == 0 || (begin && first_value != begin->value))
	{
		printf("%d_%d\n", begin->min_value, begin->value);
		begin = begin->next;
		i++;
	}
	printf("\n");
}

int ft_is_sorted(t_elem *begin)
{
	int first_value;
	int i;

	i = 0;
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
int ft_need_round_sorted(t_elem *begin)
{
	int first_value;
	int i;

	i = 0;
	first_value = begin->value;
	while (i == 0 || (begin && first_value != begin->value))
	{
		if (ft_is_sorted(begin))
			return (i);
		begin = begin->next;
		i++;
	}
	return (-1);
}
*/

int ft_need_round_for_sort(t_elem *begin)
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


void ft_swap_list(t_elem *begin)
{
	int temp;

	if (!begin)
		return ;
	if (!(begin->next))
		return ;
	temp = begin->value;
	begin->value = begin->next->value;
	begin->next->value = temp;
	printf("sa\n");
}


void ft_round_list(t_elem **begin)
{
	if (*begin && (*begin)->next)
		*begin = (*begin)->next;
	printf("ra\n");
}

void ft_revers_round_list(t_elem **begin)
{
	if (*begin && (*begin)->prev)
		*begin = (*begin)->prev;
	printf("rra\n");
}



t_elem *ft_cut_elem(t_elem **begin)
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


void ft_paste_elem(t_elem **begin, t_elem **new)
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


void ft_push_list(t_elem **arra, t_elem **arrb, char push)
{
	t_elem *cut_list;

	if (*arra == NULL)
		return ;
	cut_list = ft_cut_elem(arra);
	ft_paste_elem(arrb, &cut_list);

	printf("p%c\n", push);
}


t_elem *ft_bubble_sort(t_elem *arr)
{
	int		j = 0;

	while (j < 100)
	{
		if (arr->value > arr->next->value && arr->next->value != arr->min_value)
			ft_swap_list(arr);

		if (ft_is_sorted(arr))
			break ;
		if (arr->value < arr->prev->value && arr->value != arr->min_value)
			ft_revers_round_list(&arr);
		else
		{
			if (ft_need_round_for_sort(arr) > 0)
				ft_round_list(&arr);
			else if (ft_need_round_for_sort(arr) < 0)
				ft_revers_round_list(&arr);
			else ft_round_list(&arr);
		}

		j++;
	}
	return (arr);
	//printf("\n%d\n", action);
}


t_elem *ft_vstavka_sort(t_elem *arra, t_elem *arrb)
{
	while (arra && arra->next && arra->next->next != arra)
	{
		if (arra->value == arra->min_value)
			ft_round_list(&arra);
		ft_push_list(&arra, &arrb, 'b');
	}
	//ft_print_list(arra);
	//ft_print_list(arrb);
	while (arrb)
	{
		if (arrb->value > arra->value && arra->value != arra->min_value)
			ft_round_list(&arra);
		else if (arrb->value < arra->value && arrb->value < arra->prev->value)
			ft_revers_round_list(&arra);
		else if (arrb->value < arra->value && arrb->value > arra->prev->value)
			ft_push_list(&arrb, &arra, 'a');
		else if (arrb->value > arra->prev->value && arra->value == arra->min_value)
			ft_push_list(&arrb, &arra, 'a');
	}
	while (arra->value != arra->min_value)
	{
		if (ft_need_round_for_sort(arra) > 0)
			ft_round_list(&arra);
		else if (ft_need_round_for_sort(arra) < 0)
			ft_revers_round_list(&arra);
	}

	return (arra);
}


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
	int arr[] = {10,3,4,5,9,13,0,6,78,8};


	//int arr[] = {1,3,4};
	argc = 100000;
	t_elem *arra;
	t_elem *arrb;


	int *mass;
	mass = ft_return_num_from_string(argc, argv);
	mass =
	mass = {10,3,4,5,9,13,0,6,78,8};
	push_swap()


	arra = ft_create_lists(arr, argc);
	//arrb = NULL;

	mass = ft_uniq_int_gen(argc);
	int i = 0;
	while (i < argc)
	{
		printf("%d\n", mass[i]);
		i++;
	}

	//ft_print_list(arra);

	/*printf("%d\n", ft_need_round_sorted(arra));
	int rounds;
	int needs = ft_is_list_sorted_and_rounded(arra, &rounds);
	printf("%d, %d\n", needs, rounds);*/

	//arra = ft_bubble_sort(arra);
	//arra = ft_vstavka_sort(arra, arrb);

	//ft_print_list(arra);
	//ft_print_list(arrb);
	return (0);
}
