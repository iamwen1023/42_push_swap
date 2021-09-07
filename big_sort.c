
#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_listd
{
	int			content;
	struct s_listd	*prev;
	struct s_listd	*next;
} t_listd;

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
	return arr;
}
void replace_by_ranking(t_listd **arr, int argc, char**argv)
{
	int i;
	int *arr_int;
	t_listd *current;

	arr_int = sort_arry(argc, argv);
	current = (*arr);
	while(current->next)
	{
		i = -1;
		while(++i < argc - 1)
		{
			if(current->content == arr_int[i])
				current->content = i;
		}
		current = current->next;
	}
	i = -1;
	while(++i < argc - 1)
	{
		if(current->content == arr_int[i])
			current->content = i;
	}
}

void radix_sort(t_listd **arr)
{
	t_listd	*arr_b;
	t_listd	*current;
	int 	mask = ~0;

	arr_b = 0;
	current = (*arr);
	 while(current->next)
	 {

	 }
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