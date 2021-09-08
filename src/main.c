#include "../push_swap.h"

int main(int argc, char **argv)
{
	t_listd *arr;

	if (check_error(argc, argv) == 1)
		error_exit();
	arr = parse_lst(argc, argv);
	if (confrim_sort(arr) == 1)
		return (0);
	if (argc <= 4)
		small_sort_3(&arr, arr);
	else if (argc <= 6)
		small_sort_5(&arr);
	else 
		radix_sort(&arr, argc-1);
	print_out(arr);
	return (0);
}