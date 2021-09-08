#include "../push_swap.h"

void radix_sort(t_listd **arr, int size)
{
	int	max_bits;
	int	i;
	int y;
	int num;
	t_listd *arr_b = 0;

	max_bits = 0;
	i = -1;
	while (((size - 1)>>max_bits) != 0)
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

