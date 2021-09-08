#include "../push_swap.h"

int main(int argc, char **argv)
{
	t_listd *arr;

	if (check_error(argc, argv) == 1)
		error_exit();
	arr = parse_lst(argc, argv);
	if (confrim_sort(arr) == 1)
		return (0);
	if (argc == 4)
		small_sort_3(&arr, arr);
	if (argc == 6)
		small_sort_5(&arr);
	print_out(arr);
	return (0);
}

// int main(int argc, char**argv)
// {
// 	t_listd *arr_a;
// 	t_listd *temp;
// 	int ans;

// 	if (argc == 1)
// 	{
// 		write(1, "Error!\n", 7);
// 		return (1);
// 	}
// 	parse_lst(argc, argv,&arr_a ,&temp);
// 	ans = the_min(arr_a);
// 	//replace_by_ranking(&arr_a, argc,argv);

// 	//print_out(arr_a);
// 	//arr_a = small_sort_5(arr_a, arr_a);
// 	printf("ans:%d", ans);
// 	return 0;
// }

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
	//print_out(arr_a);
	
	radix_sort(&arr_a, argc-1);
	print_out(arr_a);
	return 0;
}
