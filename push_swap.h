#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <libft.h>

typedef struct	s_inlst
{
	int			content;
	struct s_inlst	*next;
	struct s_inlst	*prev;
}				t_inlst;


t_inlst			*ft_inlstnew(int content);
void			ft_inlstadd_back(t_inlst **lst, t_inlst *new);
t_inlst			*ft_inlstlast(t_inlst *lst);
void			ft_inlstclear(t_inlst **lst);

void	sa(t_inlst **head);
void	sb(t_inlst **head);
void	ss(t_inlst **ahead, t_inlst **bhead);
void	pb(t_inlst **ahead, t_inlst **bhead);
void	pa(t_inlst **ahead, t_inlst **bhead);
void	ra(t_inlst **head);
void	rb(t_inlst **head);
void	rr(t_inlst **ahead, t_inlst **bhead);
void	rra(t_inlst **head);
void	rrb(t_inlst **head);
void	rrr(t_inlst **ahead, t_inlst **bhead);


void	atob(int n, t_inlst **ahead, t_inlst **bhead);
void	btoa(int n, t_inlst **ahead, t_inlst **bhead);


// void			ft_lstadd_front(t_list **lst, t_list *new);
// int				ft_lstsize(t_list *lst);
// void			ft_lstdelone(t_list *lst, void (*del)(void *));
// void			ft_lstiter(t_list *lst, void (*f)(void *));
// t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
// 										void (*del)(void *));

#endif