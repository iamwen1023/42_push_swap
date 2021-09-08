#include "../push_swap.h"

void bin(unsigned n)
{
    unsigned i;
    for (i = 1 << 31; i > 0; i = i / 2)
        (n & i) ? ft_putstr_fd("1", 1) : ft_putstr_fd("0", 1);
}

void print_out_3(t_listd *arr_t)
{
	if (arr_t == 0)
	{
		printf("arr: []\n");
		return;
	}
	printf("arr : [");
	while (arr_t->next)
	{	
		
		printf(" %d: ",arr_t->content);
		bin((unsigned)arr_t->content);
		arr_t = arr_t->next;
	}
	printf(" %d: ",arr_t->content);
	bin((unsigned)arr_t->content);
	printf("\n");
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

