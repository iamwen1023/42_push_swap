#include "../push_swap.h"

void rotate_a_np(t_listd **lst)
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

void rotate_b_np(t_listd **lst)
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

void r_rotate_a_np(t_listd **lst)
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

void r_rotate_b_np(t_listd **lst)
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