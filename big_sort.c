
#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

int *sort_arry(int argc, char**argv)
{
	int *arr;
	int i;

	arr = (int*)malloc(argc * sizeof(int));
	if (!arr)
		return (0);
	i = 0;
	while(i < argc - 1)
	{
		arr[i] = ft_atoi(argv[i+1]);
		i++;
	}
	
	return arr;
}

int main (int argc, char** argv)
{
	int *arr;

	arr = sort_arry(argc, argv);
	return 0 ;

}