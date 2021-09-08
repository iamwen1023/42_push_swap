#include "../push_swap.h"

int the_max(t_listd *arr)
{
	int max;

	max = arr->content;
	while(arr)
	{
		if (arr->content > max)
			max = arr->content;
		arr = arr->next;
	}
	return (max);
}

int the_min(t_listd *arr)
{
	int min;

	min = arr->content;
	while(arr)
	{
		if (arr->content < min)
			min = arr->content;
		arr = arr->next;
	}
	return (min);
}

void	small_sort_3(t_listd **arr , t_listd *current)
{
	if (current->content == the_max(*arr))
	{
		current = current->next;
		if (current->content == the_min(*arr))
			rotate_a(arr);
		else
		{
			swap_a(arr);
			r_rotate_a(arr);
		}
	}
	else if (current->content == the_min(*arr))
	{
		swap_a(arr);
		rotate_a(arr);
	}
	else 
	{
		current = current->next;
		if (current->content == the_min(*arr))
			swap_a(arr);
		else
			r_rotate_a(arr);
	}
}

void	small_sort_5(t_listd **arr)
{
	t_listd *arr_b;

	arr_b = 0;
	push_b(arr, &arr_b);
	push_b(arr, &arr_b);
	if (confrim_sort(*arr) == 0)
		small_sort_3(arr , *arr);
	while(confrim_sort(*arr) == 0 || arr_b)
	{
		if ((arr_b) && arr_b->content < (*arr)->content)
			push_a(arr, &arr_b);
		else if (confrim_sort(*arr) == 1 && arr_b->content > the_max(*arr))
		{
			push_a(arr, &arr_b);
			rotate_a(arr);
		}
		else
			rotate_a(arr);
	}
}