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



typedef struct		s_elem
{
	int				value;
	int				medium_value;
	int				min_value;
	int				max_value;
	struct s_elem	*next;
	struct s_elem	*prev;
}					t_elem;


void *ft_error(int errnum);
void ft_list_del(t_elem *begin);

t_elem	*ft_create_elem(int value, int min_value, int medium_value, int max_value)
{
	t_elem *tmp;

	tmp = (t_elem *)ft_memalloc(sizeof(t_elem));
	if (!tmp)
		return (NULL);
	tmp->value = value;
	tmp->min_value = min_value;
	tmp->medium_value = medium_value;
	tmp->max_value = max_value;
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


int ft_find_max_value(int *arr, int argc)
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
	return(max_value);
}


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



int ft_find_medium_value(int *arr, int argc)
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
	//printf("%d\n", medium);
	free(sorted);
	return (medium);
}

t_elem	*ft_create_lists(int *arr, int argc)
{
	int i;
	int value[3];
	t_elem *begin;
	t_elem *tmp;

	value[0] = ft_find_min_value(arr, argc);
	value[1] = ft_find_medium_value(arr, argc);
	value[2] = ft_find_max_value(arr, argc);
	begin = ft_create_elem(arr[0], value[0], value[1], value[2]);
	tmp = begin;
	i = 1;
	while (i < argc)
	{
		if (!tmp || !(tmp->next = ft_create_elem(arr[i], value[0], value[1], value[2])))
		{
			ft_list_del(begin);
			return (NULL);
		}
		tmp->next->prev = tmp;
		tmp = tmp->next;
		i++;
	}
	tmp->next = begin;
	begin->prev = tmp;
	return (begin);
}


void ft_print_list(t_elem *begin, char stek)
{
	int first_value;
	int i;

	i = 0;
	printf("_%c_\n", stek);
	if (begin == NULL)
	{
		printf("NULL\n");
		return ;
	}
	first_value = begin->value;
	while (i == 0 || (begin && first_value != begin->value))
	{
		printf("%d\n", begin->value);
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

int ft_need_rotate_for_sort(t_elem *begin)
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



void ft_swap_list(t_elem *begin, char stek)
{
	int temp;

	if (!begin)
		return ;
	if (!(begin->next))
		return ;
	temp = begin->value;
	begin->value = begin->next->value;
	begin->next->value = temp;
	if (stek == 'a' || stek == 'b')
		printf("s%c\n", stek);
}


void ft_round_list(t_elem **begin, char stek)
{
	if (*begin && (*begin)->next)
		*begin = (*begin)->next;
	if (stek == 'a' || stek == 'b' || stek == 'r')
		printf("r%c\n", stek);
}

void ft_revers_round_list(t_elem **begin, char stek)
{
	if (*begin && (*begin)->prev)
		*begin = (*begin)->prev;
	if (stek == 'a' || stek == 'b' || stek == 'r')
		printf("rr%c\n", stek);
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


void ft_push_list(t_elem **arra, t_elem **arrb, char stek)
{
	t_elem *cut_list;

	if (*arra == NULL)
		return ;
	cut_list = ft_cut_elem(arra);
	ft_paste_elem(arrb, &cut_list);
	if (stek == 'a' || stek == 'b')
		printf("p%c\n", stek);
}


t_elem *ft_bubble_sort(t_elem *arr)
{
	int		j = 0;

	while (1)
	{
		if (arr->value > arr->next->value && arr->next->value != arr->min_value)
			ft_swap_list(arr, 'a');

		if (ft_is_sorted(arr))
			break ;
		if (arr->value < arr->prev->value && arr->value != arr->min_value)
			ft_revers_round_list(&arr, 'a');
		else
		{
			if (ft_need_rotate_for_sort(arr) > 0)
				ft_round_list(&arr, 'a');
			else if (ft_need_rotate_for_sort(arr) < 0)
				ft_revers_round_list(&arr, 'a');
			else
				ft_round_list(&arr, 'a');
		}

		//j++;
	}
	return (arr);
	//printf("\n%d\n", action);
}


int ft_count_of_element_in_stek(t_elem *begin)
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


int ft_min_count_of_rounding(t_elem *begin, int value)
{
	int round_count;
	int list_count;

	round_count = 0;
	if (begin == NULL)
		return (0);
	if (begin->next == NULL)
		return (0);
	list_count = ft_count_of_element_in_stek(begin);
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


int ft_min_count_of_round_for_insert(t_elem *begin, int value)
{
	int round_count;
	int list_count;

	round_count = 0;
	list_count = ft_count_of_element_in_stek(begin);
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



int ft_min_count_of_rounding_steks(t_elem *arra, t_elem *arrb)
{
	int round_count;
	int list_countb;
	int round_values[3];
	int min_values[3];
	t_elem *begin;

	round_count = 0;
	begin = arrb;
	list_countb = ft_count_of_element_in_stek(arrb);
	min_values[0] = 0;
	min_values[1] = 0;
	min_values[2] = 2147483646;
	while (arrb && round_count < list_countb)
	{
		round_values[0] = ft_min_count_of_rounding(begin, arrb->value);
		round_values[1] = ft_min_count_of_round_for_insert(arra, arrb->value);

		if (ft_znak(round_values[0]) == ft_znak(round_values[1]))
			round_values[2] = ft_max(ft_abs(round_values[0]), ft_abs(round_values[1]));
		else
			round_values[2] = ft_abs(round_values[0]) + ft_abs(round_values[1]);

		if (round_values[2] < min_values[2])
			ft_memcpy((void *)min_values, (void *)round_values, 12);
		arrb = arrb->next;
		round_count++;
	}
	if (ft_znak(min_values[0]) == ft_znak(min_values[0]))
		return (ft_znak(min_values[0]) + ft_znak(min_values[0]));
	return (ft_znak(min_values[0]));
}


int ft_is_num_are_sorted(t_elem *begin)
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
		if (sorted < begin->value && sorted > (begin->value - delta))// && (begin->value - 100000) + 100000 == begin->value)
		//if (sorted < begin->value)
			sorted = begin->value;
		begin = begin->next;
	}
	if (sorted <= begin->value && sorted > (begin->value - delta))
		return(1);
	return(0);
}

/*
while (arra && ft_need_rotate_for_sort(arra) == 0)
{
	if (arra->value == arra->min_value || ft_is_num_are_sorted(arra))
	{
		if (arra->next->value < arra->value && arra->next->value > arra->prev->value)
		{
			ft_swap_list(arra, 'a');
			ft_round_list(&arra, 'a');
		}
		ft_round_list(&arra, 'a');
	}
	if (arra->next->value < arra->value && arra->next->value > arra->prev->value)
		ft_swap_list(arra, 'a');

	ft_push_list(&arra, &arrb, 'b');
}
*/


t_elem *ft_vstavka_sort(t_elem *arra, t_elem *arrb)
{
	/*
	int flag;
	flag = 0;
	while (arra && ft_need_rotate_for_sort(arra) == 0)
	{
		if (arra->value == arra->min_value)
		{
			ft_round_list(&arra, 'a');
			flag = 1;
		}
		if (flag == 1 && arra->value > arra->prev->value)
			ft_round_list(&arra, 'a');

		ft_push_list(&arra, &arrb, 'b');
	}*/

	while (arra && ft_need_rotate_for_sort(arra) == 0)
	{
		if (arra->value == arra->min_value || ft_is_num_are_sorted(arra))
		{
			//if (arra->next->value < arra->value && arra->next->value > arra->prev->value)
			//{
			//	ft_swap_list(arra, 'a');
			//	ft_round_list(&arra, 'a');
			//}
			ft_round_list(&arra, 'a');
		}
		else
		{
			ft_push_list(&arra, &arrb, 'b');
			if (arrb->value < arra->medium_value && arrb->next && arrb->next->next != arrb)
				ft_round_list(&arrb, 'b');
		}
		//ft_print_list(arra, 'a');
		//ft_print_list(arrb, 'b');
	}





/*	while (arra && arra->next && arra->next->next != arra)
	{
		if (arra->value == arra->min_value)
			ft_round_list(&arra, 'a');
		ft_push_list(&arra, &arrb, 'b');
	}
*/	//ft_print_list(arra, 'a');
	//printf("%d_%d_%d\n", arra->max_value, arra->min_value, arra->max_value - arra->min_value);
	//ft_print_list(arrb, 'b');
	while (arrb)
	{
		if (ft_min_count_of_rounding_steks(arra, arrb) == 2)
		{
			ft_round_list(&arrb, 'r');
			ft_round_list(&arra, 0);
		}
		else if (ft_min_count_of_rounding_steks(arra, arrb) == -2)
		{
			ft_revers_round_list(&arrb, 'r');
			ft_revers_round_list(&arra, 0);
		}
		else if (ft_min_count_of_rounding_steks(arra, arrb) == 1)
			ft_round_list(&arrb, 'b');
		else if (ft_min_count_of_rounding_steks(arra, arrb) == -1)
			ft_revers_round_list(&arrb, 'b');
		else if (ft_min_count_of_round_for_insert(arra, arrb->value) > 0)
			ft_round_list(&arra, 'a');
		else if (ft_min_count_of_round_for_insert(arra, arrb->value) < 0)
			ft_revers_round_list(&arra, 'a');
		else if (ft_min_count_of_round_for_insert(arra, arrb->value) == 0)
			ft_push_list(&arrb, &arra, 'a');
	}

	while (arra->value != arra->min_value)
	{
		if (ft_need_rotate_for_sort(arra) > 0)
			ft_round_list(&arra, 'a');
		else if (ft_need_rotate_for_sort(arra) < 0)
			ft_revers_round_list(&arra, 'a');
	}

	return (arra);
}



char **open_and_read_command(char *name)
{
	int file;
	int red;
	char *str;
	char buf[1001];

	str = NULL;
	file = open(name, O_RDONLY);
	while ((red = read(file, buf, 1000)))
	{
		buf[red] = '\0';
		//printf("%s\n", ar[i]);
		str = ft_strjoin_free(str, buf, 1, 0);
	}
	return (ft_strsplit(str, '\n'));
}



void *ft_error(int errnum)
{
	ft_putstr_fd("Error\n", 2);
	exit (0);
	return (NULL);
}


int ft_is_not_number(char **str)
{
	int i;
	char *tmp;

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



int ft_str_not_int_number(char *str)
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


int *ft_arr_int_from_str(char **argv, int argc)
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


int ft_have_repeat_num(int *arr, int argc)
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
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}



void ft_list_del(t_elem *begin)
{
	int list_count;
	int i;
	t_elem *tmp;

	i = 1;
	list_count = ft_count_of_element_in_stek(begin);
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


int *ft_valid_arr(int *argc, char **argv)
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
		ft_str_arr_free(argv);
	return (arr);
}







int		main(int argc, char **argv)
{
	//int arr[] = {10,3,4,5,9,13,0,6,78,8};
	//argc = 10;


	//char **arv;
	int *arr;
	t_elem *arra;
	t_elem *arrb;
	//arv = open_and_read_command("arr.txt");

	//printf("%d\n", argc);
	//printf("%s\n", argv[1]);

	if (argc == 1)
		return (0);
	if (!(arr = ft_valid_arr(&argc, argv)))
		ft_error(0);
	/*
	if (argc == 2)
	{
		argv = ft_strsplit(argv[], ' ');
		argc = 0;
	}
	else
	{
		argv++;
		argc--;
	}
	if (!(arr = ft_arr_int_from_str(argv, &argc)))
		ft_error(0);
	*/
	if (ft_have_repeat_num(arr, argc))
	{
		free(arr);
		ft_error(0);
	}

	arra = ft_create_lists(arr, argc);
	arrb = NULL;

	free(arr);

	if (!arra)
		ft_error(0);

	//char *str = ft_strdup("222\t ");
	//printf("%s__%d__%d\n", str, ft_str_not_int_number(str), atoi(str));

	//ft_print_list(arra);

	/*printf("%d\n", ft_need_round_sorted(arra));
	int rounds;
	int needs = ft_is_list_sorted_and_rounded(arra, &rounds);
	printf("%d, %d\n", needs, rounds);*/

	//arra = ft_bubble_sort(arra);
	arra = ft_vstavka_sort(arra, arrb);


	//ft_print_list(arra, 'a');
	//ft_print_list(arrb, 'b');

	ft_list_del(arra);
	ft_list_del(arrb);

	return (0);
}
