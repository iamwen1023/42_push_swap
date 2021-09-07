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

typedef struct s_stack
{
	struct t_listd	*head;
	struct t_listd	*tail;
	int				size;
} t_stack;

t_listd	*ft_lstnew_Doubly(int content);
void	ft_lstadd_front_Doubly(t_listd **lst, t_listd *new);
void	ft_lstadd_back_Doubly(t_listd **lst, t_listd *new);
void	print_out(t_listd *arr_t);
void	ft_lstdel_Doubly(t_listd **lst, t_listd *del);
void	swap_a(t_listd **lst);
void	swap_b(t_listd **lst);
void	push_a(t_listd **lst_a, t_listd **lst_b);
void	push_b(t_listd **lst_a, t_listd **lst_b);
void	rotate_a(t_listd **lst);
void	rotate_b(t_listd **lst);
void	r_rotate_a(t_listd **lst);
void	r_rotate_b(t_listd **lst);
void	parse_lst(int argc, char **argv, t_listd **arr, t_listd **temp);
int		confrim_sort(t_listd *arr);
int		the_max(t_listd *arr);
int		the_min(t_listd *arr);
t_listd	*small_sort_3(t_listd *arr , t_listd *current);
t_listd *small_sort_5(t_listd *arr , t_listd *current);

#endif