#include <stdio.h>

void	send_message(int message)
{
	int	i;
	int	ret;

    i = 0;
	while (++i < 32)
	{
		printf("%d\n", (message) & (0x80));
        message = message << 1;
	}

}
int main()
{   
    int a = 9;
    send_message(a);

    return 0;
}