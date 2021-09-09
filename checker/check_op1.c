#include "../push_swap.h"

void swap_a_np(t_listd **lst)
{
	t_listd	*temp;

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

void swap_b_np(t_listd **lst)
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

void push_a_np(t_listd **lst_a, t_listd **lst_b)
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

void push_b_np(t_listd **lst_a, t_listd **lst_b)
{
	t_listd *temp;

	if (!(*lst_a))
		return;
	temp = ft_lstnew_Doubly((*lst_a)->content);
	temp->next =(*lst_a)->next;
	temp->prev = (*lst_a)->prev;
	ft_lstadd_front_Doubly(lst_b, temp);
	ft_lstdel_Doubly(lst_a, *lst_a);
}