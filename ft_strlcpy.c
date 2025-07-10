/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 12:33:06 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/07/10 20:30:07 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	src_size;

	if (dest == NULL || src == NULL)
	{
		errno = EINVAL;
		return (0);
	}
	src_size = ft_strlen(src);
	if (!destsize)
	{
		if (src_size > 0)
			errno = EINVAL;
		return (src_size);
	}
	while (*src && destsize > 1)
	{
		*dest = *src;
		dest++;
		src++;
		destsize--;
	}
	*dest = '\0';
	return (src_size);
}
