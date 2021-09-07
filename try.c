#include "push_swap.h"
#include <stdio.h>

void	send_message(int *message)
{
	int	i;
	int	ret;

    i = -1;
	while (++i < 5)
	{
		printf("%d : ", (message[i]) & (1));
		if (((message[i]) & (1)) == 0)
			printf("group b\n");
		else 
			printf("group a\n");
	}

}
int main()
{   
    int *a;
	int i = -1;

	a = malloc(5*sizeof(int));
	if(!a)
		return 1;
	while (++i < 5)
	{
		a[i] = i;
	}
    send_message(a);

    return 0;
}