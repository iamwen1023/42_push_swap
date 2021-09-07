#include "push_swap.h"

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void print_out_2(int *arr, int argc)
{
	int i = 0;
	printf("arr: ");
	while(i < argc -1)
	{
		printf("%d, ",arr[i]);
		i++;
	}
	printf("\n");
}

int *sort_arry(int argc, char**argv)
{
	int *arr;
	int i;
	int y;

	arr = (int*)malloc((argc-1) * sizeof(int));
	if (!arr)
		return (0);
	i = -1;
	while(++i < argc - 1)
		arr[i] = ft_atoi(argv[i+1]);
	i = -1;
	while(++i < argc-2)
	{
		y = -1;
		while(++y < argc-2-i)
		{
			if (arr[y] > arr[y+1])
				swap(&arr[y], &arr[y+1]);
		}
	}
	// printf("sort_arry:\n");
	// print_out_2(arr, argc);
	return arr;
}
void replace_by_ranking(t_listd **arr, int argc, char**argv)
{
	int i;
	int *arr_int;
	t_listd *current;

	arr_int = sort_arry(argc, argv);
	current = (*arr);
	while(current)
	{
		i = -1;
		while(++i < argc - 1)
		{
			if(current->content == arr_int[i])
			{
				current->content = i;
				break;
			}
		}
		current = current->next;
	}
}

void radix_sort_old(t_listd **arr)
{
	t_listd	*arr_b;
	t_listd	*current;
	int		steps = 0;

	arr_b = 0;
	current = (*arr);
	while (current)
	{		
		if (((current->content) & 1) == 0)
		{
			while(steps > 0)
			{
				rotate_a(arr);
				steps--;
			}
			push_b(arr , &arr_b);
		}	
		else 
			steps++;
		current = current->next;
	}
	current = arr_b;
	while(arr_b)
	{
		push_a(arr , &arr_b);
	}
	current = (*arr);
		while (current)
	{		
		if (((current->content) & (1<<1)) == 0)
		{
			while(steps > 0)
			{
				rotate_a(arr);
				steps--;
			}
			push_b(arr , &arr_b);
		}	
		else 
			steps++;
		current = current->next;
	}
	while(arr_b)
	{
		push_a(arr , &arr_b);
	}
	current = (*arr);
		while (current)
	{		
		if (((current->content) & (1<<2)) == 0)
		{
			while(steps > 0)
			{
				rotate_a(arr);
				steps--;
			}
			push_b(arr , &arr_b);
		}	
		else 
			steps++;
		current = current->next;
	}
	// printf("arr a : ");
	// print_out(*arr);
	// printf("\narr b : ");
	// print_out(arr_b);
	// printf("\n");
}
void radix_sort(t_listd **arr, int size)
{
	int max_num;
	int	max_bits;
	int	i;
	int y;
	int num;
	t_listd *arr_b = 0;

	max_num = size - 1;
	max_bits = 0;
	i = -1;
	while ((max_num>>max_bits) != 0)
		++max_bits;
	while(++i < max_bits)
	{
		y = -1;
		while (++y < size)
		{
			num = (*arr)->content;
			if ((num>>i)&1)
				rotate_a(arr);
			else
				push_b(arr, &arr_b);
		}
		while(arr_b)
			push_a(arr, &arr_b);
	}
}

int main(int argc, char**argv)
{
	t_listd *arr_a;
	t_listd *temp;

	if (argc == 1)
	{
		write(1, "Error!\n", 7);
		return (1);
	}
	parse_lst(argc, argv,&arr_a ,&temp);
	//print_out(arr_a);
	replace_by_ranking(&arr_a, argc,argv);
	// arr = malloc(100 *sizeof(int));
	// if (!arr)
	// 	return 1;
	
	radix_sort(&arr_a, argc-1);
	//print_out(arr_a);
	return 0;
}
// int main (int argc, char** argv)
// {
// 	int *arr;
// 	int i = -1;

// 	arr = sort_arry(argc, argv);
// 	printf("arr: ");
// 	while(++i < argc -1)
// 	{
// 		printf("%d, ",arr[i]);
// 	}
// 	printf("\n");
// 	free(arr);
// 	return 0 ;

// }