#ifndef GNL_H
# define GNL_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void		*content;
	struct s_list	*next;
}	t_list;

char    *get_next_line(int fd);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstclear(t_list **lst, int (*del)(void *));
int		ft_lstdelone(t_list *lst, int (*del)(void *));
void	ft_lstiter(t_list *lst, int (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), int (*del)(void *));
t_list	*ft_lstnew(void *content);
int	ft_lstsize(t_list *lst);

#endif
