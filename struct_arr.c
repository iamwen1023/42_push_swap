#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	int			content;
	struct s_list	*last;
	struct s_list	*next;
} t_list;


t_list	*ft_lstnew(int	content)
{
	t_list		*re;

	re = (t_list *)malloc(sizeof(t_list));
	if (!re)
		return (0);
	re->content = content;
	re->next = 0;
	return (re);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new)
		new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
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
}

void	ft_lstdelone(t_list *lst)
{
	t_list *temp;

	if (!lst)
		return ;
	if (lst->last)
	{
		temp = lst->last;
		temp->next = lst->next;
	}
	else
		lst = lst->next;
	free(lst);
}

int remove_by_index(t_list **head, int n) {
    int i = 0;
    int retval = -1;
    t_list *current = *head;
    t_list *temp_node = NULL;

    if (n == 0) {
        temp_node = (*head)->next;
    	retval = (*head)->content;
    	free(*head);
    	*head = temp_node;
		return retval;
    }

    for (i = 0; i < n-1; i++) {
        if (current->next == NULL) {
            return -1;
        }
        current = current->next;
    }

    temp_node = current->next;
    retval = temp_node->content;
    current->next = temp_node->next;
    free(temp_node);

    return retval;

}

void	ft_lstswap(t_list **a , t_list **b)
{
	t_list *temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	t_list *arr;
	t_list *arr2;
	t_list *arr3;
	int a = 8;
	int b = 10;
	int c = 12;
	arr = ft_lstnew(a);
	arr2 = ft_lstnew(b);
	arr3 = ft_lstnew(c);
	ft_lstadd_back(&arr, arr2);
	ft_lstadd_back(&arr, arr3);
	ft_lstdelone(arr2);
	printf("n:%d\n",arr->content);
	
	return 0;
}