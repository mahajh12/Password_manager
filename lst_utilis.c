#include "pm.h"

void	ft_lstadd_back(t_data **lst, t_data *new)
{
	t_data	*l;

	if (*lst)
	{
		l = ft_lstlast(*lst);
		l -> next = &*new;
	}
	else
		*lst = new;
}

void	ft_lstadd_front(t_data **lst, t_data *new)
{
	if (lst == NULL)
		*lst = new;
	new -> next = *lst;
	*lst = new;
}

void ft_lstdelone(t_data *lst)
{
    if (!lst)
        return;
    free(lst);
}

void ft_lstclear(t_data **lst)
{
    if (!lst)
        return;
    while (*lst != NULL)
    {
        t_data *tmp = *lst;
        *lst = (*lst)->next;
        ft_lstdelone(tmp);
    }
}

int	ft_lstsize(t_data *lst)
{
	int	len;

	len = 0;
	while (lst != NULL)
	{
		lst = lst -> next;
		len++;
	}
	return (len);
}


