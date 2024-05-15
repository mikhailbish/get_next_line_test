#include "gnl.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

int		ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (lst && *lst)
	{
//	printf("in lstadd back\n");
		ptr = ft_lstlast(*lst);
		ptr->next = new;
			
	}
	else if (lst)
		*lst = new;
	if (lst)
		return (1);
	return (0);
}

int	ft_lstclear(t_list **lst, int (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	if (!del || !lst)
		return (0);
	current = *lst;
	while (current != 0)
	{
		next = current->next;
		ft_lstdelone(current, del);
		current = next;
	}
	*lst = 0;
	return (1);
}

int	ft_lstdelone(t_list *lst, int (*del)(void *))
{
	if (lst)
	{
		del && del(lst->content);
		free(lst);
		return (1);
	}
	return (0);
}

void	ft_lstiter(t_list *lst, int (*f)(void *))
{
	while (lst)
	{
		f && f(lst->content);
		lst = lst->next;
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), int (*del)(void *))
{
	t_list	*new_list_start;
	t_list	*tmp_node;
	void	*new_content;

	new_list_start = 0;
	tmp_node = 0;
	new_content = 0;
	if (!f || !del)
		return (0);
	while (lst)
	{
		new_content = f(lst->content);
		tmp_node = ft_lstnew(new_content);
		if (!tmp_node)
		{
			del(new_content);
			ft_lstclear(&new_list_start, del);
			return (0);
		}
		ft_lstadd_back(&new_list_start, tmp_node);
		lst = lst->next;
	}
	return (new_list_start);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*ptr;

	ptr = malloc(sizeof(t_list));
	if (!ptr)
		return (0);
	ptr->content = content;
	ptr->next = 0;
	return (ptr);
}

int	ft_lstsize(t_list *lst)
{
	int	counter;

	counter = 0;
	if (!lst)
		return (counter);
	counter++;
	while (lst->next)
	{
		counter++;
		lst = lst->next;
	}
	return (counter);
}
