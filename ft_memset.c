/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 11:21:12 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/07/10 20:11:10 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	if (s == NULL || n == 0)
	{
		errno = EINVAL;
		return (NULL);
	}
	ptr = (unsigned char *)s;
	while (n--)
		*ptr++ = (unsigned char)c;
	return (s);
}
