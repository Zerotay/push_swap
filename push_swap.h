#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <libft.h>

typedef struct	s_inlst
{
	int			content;
	struct	s_inlst	*next;
	struct	s_inlst	*prev;
}				t_inlst;

t_inlst	*ft_inlstnew(int content);
void	ft_inlstadd_back(t_inlst **lst, t_inlst *new);
t_inlst	*ft_inlstlast(t_inlst *lst);
void	ft_inlstclear(t_inlst **lst);

int		sa(t_inlst **head);
int		sb(t_inlst **head);
int		ss(t_inlst **ahead, t_inlst **bhead);
int		pb(t_inlst **ahead, t_inlst **bhead);
int		pa(t_inlst **ahead, t_inlst **bhead);
int		ra(t_inlst **head);
int		rb(t_inlst **head);
int		rr(t_inlst **ahead, t_inlst **bhead);
int		rra(t_inlst **head);
int		rrb(t_inlst **head);
int		rrr(t_inlst **ahead, t_inlst **bhead);

int		aif3(t_inlst **ahead, t_inlst **bhead);
int		bif3(t_inlst **ahead, t_inlst **bhead);
void	onlyif3(t_inlst **ahead);
void	onlyif5(t_inlst **ahead, t_inlst **bhead);

int		atob(int n, t_inlst **ahead, t_inlst **bhead);
int		btoa(int n, t_inlst **ahead, t_inlst **bhead);

#endif