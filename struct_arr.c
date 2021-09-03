#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_listd
{
	int			content;
	struct s_listd	*prev;
	struct s_listd	*next;
} t_listd;


t_listd	*ft_lstnew_Doubly(int content)
{
	t_listd		*re;

	re = (t_listd *)malloc(sizeof(t_listd));
	if (!re)
		return (0);
	re->content = content;
	re->next = 0;
	re->prev = 0;
	return (re);
}

void	ft_lstadd_front_Doubly(t_listd **lst, t_listd *new)
{
	if (new)
		new->next = *lst;
	if	(*lst)
		(*lst)->prev = new;
	*lst = new;
}

void	ft_lstadd_back_Doubly(t_listd **lst, t_listd *new)
{
	t_listd	*current;

	if (!(*lst))
	{
		(*lst) = new;
		return ;
	}
	current = (*lst);
	while (current->next != 0)
	{
		current = current->next;
	}
	current->next = new;
	new->prev = current;
}
void print_out(t_listd *arr_t)
{
	printf("arr :");
	while (arr_t->next)
	{	
		
		printf("%d",arr_t->content);
		arr_t = arr_t->next;
	}
	printf("%d",arr_t->content);
	printf("arr rev:");
	while (arr_t->prev)
	{	
		printf("%d",arr_t->content);
		arr_t = arr_t->prev;
	}
	printf("%d",arr_t->content);
	printf("\n");
}

void	ft_lstdel_Doubly(t_listd **lst, t_listd *del)
{
	if (!(*lst) || !del)
		return ;
	if (*lst == del)
		*lst = del->next;
	if (del->prev == 0 || del->next == 0)
	{
		if (del->prev == 0)
			(*lst)->prev = 0;
		if (del->next == 0)
			(*lst)->next = 0;
	}
	else 
	{
		if (del->next != 0)
			del->next->prev = del->prev;
		if (del->prev != 0)
			del->prev->next = del->next;
	}
	free(del);
}

void operation_swap(t_listd **lst)
{
	t_listd *temp;

	if (!(*lst))
		return;
	temp = ft_lstnew_Doubly((*lst)->content);
	temp->next = (*lst)->next;
	temp->prev = (*lst)->prev;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next = (*lst)->next;
	(*lst)->next->content = temp->content;
	free(temp);
}
void operation_push(t_listd **lst_a, t_listd **lst_b)
{
	t_listd *temp;

	if (!(*lst_b))
		return;
	temp = ft_lstnew_Doubly((*lst_b)->content);
	temp->next =(*lst_b)->next;
	temp->prev = (*lst_b)->prev;
	ft_lstadd_front_Doubly(lst_a, temp);
	ft_lstdel_Doubly(lst_b, *lst_b);
}
void operation_rotate(t_listd **lst)
{
	t_listd *temp;
	t_listd *key;

	key = (*lst);
	temp = (*lst);
	(*lst) = (*lst)->next;
	while(temp->next != 0)
		temp = temp->next;
	temp->next = key;
	key->prev = temp;
	key->next = 0;
	(*lst)->prev = 0;
}

void operation_r_rotate(t_listd **lst)
{
	t_listd *temp;
	t_listd *key;

	temp = (*lst);
	key = temp;
	while(key->next != 0)
		key = key->next; 
	key->prev->next = 0;
 	temp->prev = key;
	key->next = temp;
	key->prev = 0;
	(*lst) = key;
}

void parse_lst(int argc, char **argv, t_listd **arr, t_listd **temp)
{
	// t_listd 	*arr;
	// t_listd		*temp;
	int i;

	i = 1;
	while (i < argc)
	{
		(*temp) = ft_lstnew_Doubly(ft_atoi(argv[i]));
		printf("new:%d\n", (*temp)->content);
		ft_lstadd_back_Doubly(arr , *temp);
		i++;
	}
	//return (arr);
}
int confrim_sort()
{
	return (1);
}
t_list *small_sort()
{

	return 0;
}
int main(int argc, char **argv)
{
	t_listd *arr;
	t_listd *arr_1;
	t_listd *arr_2;
	int i = 1;

	if (argc == 1)
	{
		write(1, "Error!\n", 7);
		return (1);
	}
	// while (i < argc)
	// {
	// 	arr = ft_lstnew_Doubly(ft_atoi(argv[i]));
	// 	ft_lstadd_back_Doubly(&arr_1 , arr);
	// 	i++;
	// }
	// i = 100;
	// while (i < 105)
	// {
	// 	arr = ft_lstnew_Doubly(i);
	// 	ft_lstadd_back_Doubly(&arr_2 , arr);
	// 	i++;
	// }
	
	parse_lst(argc, argv,&arr ,&arr_1 );
	print_out(arr);

	return 0;
}