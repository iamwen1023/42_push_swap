#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	int			content;
	struct s_list	*prev;
	struct s_list	*next;
} t_list;


t_list	*ft_lstnew_Doubly(int content)
{
	t_list		*re;

	re = (t_list *)malloc(sizeof(t_list));
	if (!re)
		return (0);
	re->content = content;
	re->next = 0;
	re->prev = 0;
	return (re);
}

void	ft_lstadd_front_Doubly(t_list **lst, t_list *new)
{
	if (new)
		new->next = *lst;
	if	(*lst)
		(*lst)->prev = new;
	*lst = new;
}

void	ft_lstadd_back_Doubly(t_list **lst, t_list *new)
{
	t_list	*current;

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

void	ft_lstdel_Doubly(t_list **lst, t_list *del)
{

	if (!(*lst) || !del)
		return ;
	
	if (*lst == del)
		*lst = del->next;
	if (del->next != 0)
		del->next->prev = del->prev;
	if (del->prev != 0)
		del->prev->next = del->next;
	free(del);
}

void print_out(t_list *arr_t)
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
	printf("final:%d",arr_t->content);
	printf("\n");

}

void operation_swap(t_list **lst)
{
	t_list *temp;

	if (!(*lst))
		return;
	temp = ft_lstnew_Doubly((*lst)->content);
	temp->next = (*lst)->next;
	temp->prev = (*lst)->prev;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next = (*lst)->next;
	(*lst)->next->content = temp->content;
}
void operation_push(t_list **lst_a, t_list **lst_b)
{
	t_list *temp;

	if (!(*lst_b))
		return;
	temp = ft_lstnew_Doubly((*lst_b)->content);
	temp->next =(*lst_b)->next;
	temp->prev = (*lst_b)->prev;
	ft_lstadd_front_Doubly(lst_a, temp);
	free(temp);
	temp = (*lst_b)->next->prev;
	ft_lstdel_Doubly(lst_b, temp);
}

int main(int argc, char *argv[])
{
	t_list *arr;
	t_list *arr_1;
	t_list *arr_2;
	int i = 0;

	while (i < 5)
	{
		arr = ft_lstnew_Doubly(i);
		ft_lstadd_back_Doubly(&arr_1 , arr);
		i++;
	}
	i = 100;
	while (i < 105)
	{
		arr = ft_lstnew_Doubly(i);
		ft_lstadd_back_Doubly(&arr_2 , arr);
		i++;
	}
	print_out(arr_1);
	print_out(arr_2);
	//operation_push(&arr_1, &arr_2);
	arr = arr_2->next->next->next;
	printf("delere : arr:%d\n", arr->content);
	ft_lstdel_Doubly(&arr_2, arr);
	print_out(arr_1);
	print_out(arr_2);
	return 0;
}