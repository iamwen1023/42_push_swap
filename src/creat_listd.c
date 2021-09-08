#include "../push_swap.h"

void print_out(t_listd *arr_t)
{
	if (arr_t == 0)
	{
		ft_putstr_fd("arr: []\n", 1);
		return;
	}
	ft_putstr_fd("arr : [" , 1);
	while (arr_t->next)
	{	
		
		ft_putnbr_fd(arr_t->content, 1);
		ft_putstr_fd(" , " , 1);
		arr_t = arr_t->next;
	}
	ft_putnbr_fd(arr_t->content, 1);
	ft_putstr_fd("] " , 1);
	ft_putstr_fd("arr rev:[", 1);
	while (arr_t->prev)
	{	
		ft_putnbr_fd(arr_t->content, 1);
		ft_putstr_fd(" , " , 1);
		arr_t = arr_t->prev;
	}
	ft_putnbr_fd(arr_t->content, 1);
	ft_putstr_fd("] " , 1);
}

t_listd	*ft_lstnew_Doubly(int content)
{
	t_listd	*re;

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

void	ft_lstdel_Doubly(t_listd **lst, t_listd *del)
{
	if (!(*lst) || !del)
		return ;
	if (*lst == del)
		*lst = del->next;
	if (del->prev == 0 && del->next == 0)
	{
		free(del);
		return ;
	}
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

