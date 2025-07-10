/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ptrlist.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 10:52:35 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/07/10 20:07:32 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>

t_ptrlist	*ft_ptrlist_new(void *ptr)
{
	t_ptrlist	*node;

	node = (t_ptrlist *)malloc(sizeof(t_ptrlist));
	if (!node)
	{
		errno = ENOMEM;
		return (NULL);
	}
	node->ptr = ptr;
	node->next = NULL;
	return (node);
}

void	ft_ptrlist_destroy(t_ptrlist *ptrlist)
{
	t_ptrlist	*tmp;

	while (ptrlist)
	{
		tmp = ptrlist->next;
		free(ptrlist->ptr);
		free(ptrlist);
		ptrlist = tmp;
	}
}

int	ft_ptrlist_prepend(t_ptrlist **ptrlist, void *ptr)
{
	t_ptrlist	*node;

	node = ft_ptrlist_new(ptr);
	if (!node)
		return (1);
	node->next = *ptrlist;
	*ptrlist = node;
	return (0);
}

void	ft_ptrlist_dellone(t_ptrlist **ptrlist, void *ptr)
{
	t_ptrlist	*curr;
	t_ptrlist	*prev;

	curr = *ptrlist;
	prev = NULL;
	while (curr)
	{
		if (curr->ptr == ptr)
		{
			if (prev)
				prev->next = curr->next;
			else
				*ptrlist = curr->next;
			free(curr->ptr);
			free(curr);
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}
