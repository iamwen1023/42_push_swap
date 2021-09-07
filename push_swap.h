#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct s_listd
{
	int			content;
	struct s_listd	*prev;
	struct s_listd	*next;
} t_listd;

int *sort_arry(int argc, char**argv);
void replace_by_ranking(t_listd **arr, int argc, char**argv);

#endif