// #include "libft/libft.h"
// #include <stdlib.h>
// #include <stdio.h>
#include "push_swap.h"

typedef struct s_listd
{
	int			content;
	struct s_listd	*prev;
	struct s_listd	*next;
} t_listd;


t_listd	*ft_lstnew_Doubly(int content)
{
	t_listd		*re;

	re = (t_listd *)malloc(sizeof(t_listd));
	if (!re)
		return (0);
	re->content = content;
	re->next = 0;
	re->prev = 0;
	return (re);
}

void	ft_lstadd_front_Doubly(t_listd **lst, t_listd *new)
{
	if (new)
		new->next = *lst;
	if	(*lst)
		(*lst)->prev = new;
	*lst = new;
}

void	ft_lstadd_back_Doubly(t_listd **lst, t_listd *new)
{
	t_listd	*current;

	if (!(*lst))
	{
		(*lst) = new;
		return ;
	}
	current = (*lst);
	while (current->next != 0)
	{
		current = current->next;
	}
	current->next = new;
	new->prev = current;
}
void print_out(t_listd *arr_t)
{
<<<<<<< HEAD
	if (arr_t == 0)
	{
		printf("arr: []\n");
		return;
	}
=======
>>>>>>> ce0de38568ed6bfe0ace698ba88b126a19a113f0
	printf("arr : [");
	while (arr_t->next)
	{	
		
		printf("%d,",arr_t->content);
		arr_t = arr_t->next;
	}
	printf("%d ]",arr_t->content);
	printf("arr rev:[");
	while (arr_t->prev)
	{	
		printf("%d,",arr_t->content);
		arr_t = arr_t->prev;
	}
	printf("%d]",arr_t->content);
	printf("\n");
}

void	ft_lstdel_Doubly(t_listd **lst, t_listd *del)
{
	if (!(*lst) || !del)
		return ;
	if (*lst == del)
		*lst = del->next;
	if (del->prev == 0 && del->next == 0)
	{
		free(del);
		return ;
	}
	if (del->prev == 0 || del->next == 0)
	{
		if (del->prev == 0)
			(*lst)->prev = 0;
		if (del->next == 0)
			(*lst)->next = 0;
	}
	else 
	{
		if (del->next != 0)
			del->next->prev = del->prev;
		if (del->prev != 0)
			del->prev->next = del->next;
	}
	free(del);
}

<<<<<<< HEAD
void swap_a(t_listd **lst)
=======
void operation_swap_a(t_listd **lst)
>>>>>>> ce0de38568ed6bfe0ace698ba88b126a19a113f0
{
	t_listd *temp;

	if (!(*lst))
		return;
	temp = ft_lstnew_Doubly((*lst)->content);
	temp->next = (*lst)->next;
	temp->prev = (*lst)->prev;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next = (*lst)->next;
	(*lst)->next->content = temp->content;
	free(temp);
	write(1, "sa\n", 3);
}

<<<<<<< HEAD
void swap_b(t_listd **lst)
=======
void operation_swap_b(t_listd **lst)
>>>>>>> ce0de38568ed6bfe0ace698ba88b126a19a113f0
{
	t_listd *temp;

	if (!(*lst))
		return;
	temp = ft_lstnew_Doubly((*lst)->content);
	temp->next = (*lst)->next;
	temp->prev = (*lst)->prev;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next = (*lst)->next;
	(*lst)->next->content = temp->content;
	free(temp);
	write(1, "sb\n", 3);
}
<<<<<<< HEAD
void push_a(t_listd **lst_a, t_listd **lst_b)
=======
void operation_push_a(t_listd **lst_a, t_listd **lst_b)
{
	t_listd *temp;

	if (!(*lst_b))
		return;
	temp = ft_lstnew_Doubly((*lst_b)->content);
	temp->next =(*lst_b)->next;
	temp->prev = (*lst_b)->prev;
	ft_lstadd_front_Doubly(lst_a, temp);
	ft_lstdel_Doubly(lst_b, *lst_b);
	write(1, "pa\n", 3);
}
void operation_push_b(t_listd **lst_a, t_listd **lst_b)
>>>>>>> ce0de38568ed6bfe0ace698ba88b126a19a113f0
{
	t_listd *temp;

	if (!(*lst_b))
		return;
	temp = ft_lstnew_Doubly((*lst_b)->content);
	temp->next =(*lst_b)->next;
	temp->prev = (*lst_b)->prev;
	ft_lstadd_front_Doubly(lst_a, temp);
	ft_lstdel_Doubly(lst_b, *lst_b);
<<<<<<< HEAD
	write(1, "pa\n", 3);
}
void push_b(t_listd **lst_a, t_listd **lst_b)
{
	t_listd *temp;

	if (!(*lst_b))
		return;
	temp = ft_lstnew_Doubly((*lst_b)->content);
	temp->next =(*lst_b)->next;
	temp->prev = (*lst_b)->prev;
	ft_lstadd_front_Doubly(lst_a, temp);
	ft_lstdel_Doubly(lst_b, *lst_b);
	write(1, "pb\n", 3);
}
void rotate_a(t_listd **lst)
{
	t_listd *temp;
	t_listd *key;

	key = (*lst);
	temp = (*lst);
	(*lst) = (*lst)->next;
	while(temp->next != 0)
		temp = temp->next;
	temp->next = key;
	key->prev = temp;
	key->next = 0;
	(*lst)->prev = 0;
	write(1, "ra\n", 3);
}
void rotate_b(t_listd **lst)
=======
	write(1, "pb\n", 3);
}
void operation_rotate_a(t_listd **lst)
>>>>>>> ce0de38568ed6bfe0ace698ba88b126a19a113f0
{
	t_listd *temp;
	t_listd *key;

	key = (*lst);
	temp = (*lst);
	(*lst) = (*lst)->next;
	while(temp->next != 0)
		temp = temp->next;
	temp->next = key;
	key->prev = temp;
	key->next = 0;
	(*lst)->prev = 0;
<<<<<<< HEAD
	write(1, "rb\n", 3);
=======
	write(1, "ra\n", 3);
>>>>>>> ce0de38568ed6bfe0ace698ba88b126a19a113f0
}
void operation_rotate_b(t_listd **lst)
{
	t_listd *temp;
	t_listd *key;

<<<<<<< HEAD
void r_rotate_a(t_listd **lst)
=======
	key = (*lst);
	temp = (*lst);
	(*lst) = (*lst)->next;
	while(temp->next != 0)
		temp = temp->next;
	temp->next = key;
	key->prev = temp;
	key->next = 0;
	(*lst)->prev = 0;
	write(1, "rb\n", 3);
}

void operation_r_rotate_a(t_listd **lst)
>>>>>>> ce0de38568ed6bfe0ace698ba88b126a19a113f0
{
	t_listd *temp;
	t_listd *key;

	temp = (*lst);
	key = temp;
	while(key->next != 0)
		key = key->next; 
	key->prev->next = 0;
 	temp->prev = key;
	key->next = temp;
	key->prev = 0;
	(*lst) = key;
	write(1, "rra\n", 4);
}

<<<<<<< HEAD
void r_rotate_b(t_listd **lst)
=======
void operation_r_rotate_b(t_listd **lst)
>>>>>>> ce0de38568ed6bfe0ace698ba88b126a19a113f0
{
	t_listd *temp;
	t_listd *key;

	temp = (*lst);
	key = temp;
	while(key->next != 0)
		key = key->next; 
	key->prev->next = 0;
 	temp->prev = key;
	key->next = temp;
	key->prev = 0;
	(*lst) = key;
	write(1, "rrb\n", 4);
}

void parse_lst(int argc, char **argv, t_listd **arr, t_listd **temp)
{
	int i;

	i = 1;
	while (i < argc)
	{
		(*temp) = ft_lstnew_Doubly(ft_atoi(argv[i]));
		ft_lstadd_back_Doubly(arr , *temp);
		i++;
	}
}
int confrim_sort(t_listd *arr)
<<<<<<< HEAD
{
	int incre;
	int decre;

	incre = 0;
	decre = 0;
	while(arr->next)
	{
		if(arr->content < arr->next->content)
			incre = 1;
		if(arr->content > arr->next->content)
			decre = 1;
		arr = arr->next;
	}
	if (decre == 1)
		return (0);
	return (incre == decre? 0 : 1);
}

int the_max(t_listd *arr)
{
	int max;

	max = arr->content;
	while(arr->next)
	{
		if (arr->content > max)
			max = arr->content;
		arr = arr->next;
	}
	if (arr->content > max)
			max = arr->content;
	return (max);
}

int the_min(t_listd *arr)
{
	int min;

	min = arr->content;
	while(arr->next)
	{
		if (arr->content < min)
			min = arr->content;
		arr = arr->next;
	}
	if (arr->content < min)
			min = arr->content;
	return (min);
}

t_listd *small_sort_3(t_listd *arr , t_listd *current)
{
	if (current->content == the_max(arr))
	{
		current = current->next;
		if (current->content == the_min(arr))
			rotate_a(&arr);
		else
		{
			swap_a(&arr);
			r_rotate_a(&arr);
		}
	}
	else if (current->content == the_min(arr))
	{
		swap_a(&arr);
		rotate_a(&arr);
	}
	else 
	{
		current = current->next;
		if (current->content == the_min(arr))
			swap_a(&arr);
		else
			r_rotate_a(&arr);
	}
	return arr;
}

t_listd *small_sort_5(t_listd *arr , t_listd *current)
{
	t_listd *arr_b;
	int 	i;
	int 	y;

	arr_b = 0;
	i = 0;
	push_b(&arr_b, &arr);
	push_b(&arr_b, &arr);
	if (confrim_sort(arr) == 0)
		arr = small_sort_3(arr , arr);
	current = arr;
	//print_out(arr);
	//print_out(arr_b);
	while(i++ < 2)
	{
		y = 0;
		while(y++ < 3+i-1)
		{
			if (arr_b->content < current->content)
			{	
				push_a(&arr, &arr_b);
				current = arr;
				break;
			}
			else if (confrim_sort(arr) == 1 && arr_b->content > the_max(arr))
			{
				push_a(&arr, &arr_b);
				rotate_a(&arr);
				current = arr;
				break;
			}
			else if(current->content == the_max(arr) && arr_b->content > the_max(arr))
			{
				rotate_a(&arr);
				push_a(&arr, &arr_b);
				while(confrim_sort(arr) == 0)
	 				rotate_a(&arr);
				current = arr;
				break;
			}
			current = current->next;
			rotate_a(&arr);
		}
	}
	//print_out(arr);
	while(confrim_sort(arr) == 0)
	 	rotate_a(&arr);
	return arr;
}

int main(int argc, char**argv)
{
	t_listd *arr_a;
	t_listd *temp;
	// t_listd *arr_1 = 0;
	// t_listd *arr_2 = 0;
	// t_listd *arr;
=======
{
	int incre;
	int decre;

	incre = 0;
	decre = 0;
	while(arr->next)
	{
		if(arr->content > arr->next->content)
			incre = 1;
		if(arr->content < arr->next->content)
			decre = 1;
		arr = arr->next;
	}
	return (incre == decre? 0 : 1);
}

int the_max(t_listd *arr)
{
	int max;

	max = arr->content;
	while(arr->next)
	{
		if (arr->content > max)
			max = arr->content;
		arr = arr->next;
	}
	if (arr->content > max)
			max = arr->content;
	return (max);
}

int the_min(t_listd *arr)
{
	int min;

	min = arr->content;
	while(arr->next)
	{
		if (arr->content < min)
			min = arr->content;
		arr = arr->next;
	}
	if (arr->content < min)
			min = arr->content;
	return (min);
}

t_listd *small_sort_3(t_listd *arr , t_listd *current)
{
	if (current->content == the_max(arr))
	{
		current = current->next;
		if (current->content == the_min(arr))
			operation_rotate_a(&arr);
		else
		{
			operation_swap_a(&arr);
			operation_r_rotate_a(&arr);
		}
	}
	else if (current->content == the_min(arr))
	{
		operation_swap_a(&arr);
		operation_rotate_a(&arr);
	}
	else 
	{
		current = current->next;
		if (current->content == the_min(arr))
			operation_swap_a(&arr);
		else
			operation_r_rotate_a(&arr);
	}
	return arr;
}

t_listd *small_sort_5(t_listd *arr , t_listd *current)
{
	t_listd *arr_b;

	arr_b = 0;
	operation_push_b(&arr_b, &arr);
	operation_push_b(&arr_b, &arr);
	arr = small_sort_3(arr , arr);
	print_out(arr);
	current = arr;
	while(current->next != 0)
	{
		//print_out(arr_b);
		printf("arr_b->content :%d\n", arr_b->content);
		printf("current->content :%d\n", current->content);
		// if (arr_b->content < current->content)
		// {	
		// 	operation_push_b(&arr, &arr_b);
		// 	printf("a < b\n");
		// 	print_out(arr);
		// 	arr_b = arr_b->next;
		// }
		current = current->next;
		operation_rotate_a(&arr);
		printf("current->content :%d\n", current->content);
		printf("current->content :%d\n", current->next->content);
		//print_out(arr);
	}
	return arr;
}

int main(int argc, char **argv)
{
	t_listd *arr_a;
	t_listd *temp;
>>>>>>> ce0de38568ed6bfe0ace698ba88b126a19a113f0
	//int i;

	if (argc == 1)
	{
		write(1, "Error!\n", 7);
		return (1);
	}

	// i = 0;
	// while (i < 5)
	// {
	// 	arr = ft_lstnew_Doubly(i);
	// 	ft_lstadd_back_Doubly(&arr_1 , arr);
	// 	print_out(arr_1);
	// 	i++;
	// }
	// i = 100;
	// while (i < 105)
	// {
	// 	arr = ft_lstnew_Doubly(i);
	// 	ft_lstadd_back_Doubly(&arr_2 , arr);
	// 	i++;
	// }
<<<<<<< HEAD
	parse_lst(argc, argv,&arr_a ,&temp);
	//print_out(arr_a);
	arr_a = small_sort_5(arr_a, arr_a);
	//print_out(arr_a);
=======
	
	parse_lst(argc, argv,&arr_a ,&temp);
	print_out(arr_a);
	arr_a = small_sort_5(arr_a, arr_a);
	print_out(arr_a);
>>>>>>> ce0de38568ed6bfe0ace698ba88b126a19a113f0
	return 0;
}