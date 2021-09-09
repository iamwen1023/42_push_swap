#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_listd
{
	int			content;
	struct s_listd	*prev;
	struct s_listd	*next;
} t_listd;

int		if_numb(char *s);
int		if_repetive_num(int *arry, int size);
int		check_error(int argc, char **argv);
void	error_exit(void);

void	print_out(t_listd *arr_t);
t_listd	*ft_lstnew_Doubly(int content);
void	ft_lstadd_front_Doubly(t_listd **lst, t_listd *new);
void	ft_lstadd_back_Doubly(t_listd **lst, t_listd *new);
void	ft_lstdel_Doubly(t_listd **lst, t_listd *del);

void	swap_a(t_listd **lst);
void	swap_b(t_listd **lst);
void	push_a(t_listd **lst_a, t_listd **lst_b);
void	push_b(t_listd **lst_a, t_listd **lst_b);
void	rotate_a(t_listd **lst);
void	rotate_b(t_listd **lst);
void	r_rotate_a(t_listd **lst);
void	r_rotate_b(t_listd **lst);
t_listd *parse_lst(int argc, char **argv);
int		confrim_sort(t_listd *arr);

int		the_max(t_listd *arr);
int		the_min(t_listd *arr);
void	small_sort_3(t_listd **arr , t_listd *current);
void	small_sort_5(t_listd **arr);

void	swap(int *xp, int *yp);
void	print_out_2(int *arr, int argc);
int		*sort_arry(int argc, char**argv);
void	replace_by_ranking(t_listd **arr, int argc, char**argv);

void	radix_sort(t_listd **arr, int size);

int		ft_strcmp(const char *s1, const char *s2);
void	check_operation_2(char *line, t_listd **arr, t_listd **arr_b);
void	check_operation(char *line, t_listd **arr, t_listd **arr_b);

void	swap_a_np(t_listd **lst);
void	swap_b_np(t_listd **lst);
void	push_a_np(t_listd **lst_a, t_listd **lst_b);
void	push_b_np(t_listd **lst_a, t_listd **lst_b);
void	rotate_a_np(t_listd **lst);
void	rotate_b_np(t_listd **lst);
void	r_rotate_a_np(t_listd **lst);
void	r_rotate_b_np(t_listd **lst);

#endif