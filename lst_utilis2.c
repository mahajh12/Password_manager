#include "pm.h"

void print_list(t_data *head)
{
    t_data *current;

    current = head;
    while (current != NULL)
    {
        t_credential *credential = current->credential;
        printf("Website: %s\n", credential->website);
        printf("Username: %s\n", credential->username);
        printf("Password: %s\n", credential->password);
        printf("\n");
        current = current->next;
    }
    printf("\n");
}

t_data	*ft_lstlast(t_data *lst)
{
	if (lst == NULL)
		return (0);
	while (lst -> next != NULL)
		lst = lst -> next;
	return (lst);
}

t_data	*ft_lstnew(t_credential *content)
{
	t_data	*new;

	new = (t_data *)malloc(sizeof(t_data));
	if (new == NULL)
		return (NULL);
	new -> credential = content;
	new -> next = NULL;
	return (new);
}