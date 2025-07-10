/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 12:34:35 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/07/10 20:29:46 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;

	if (dest == NULL || src == NULL)
	{
		errno = EINVAL;
		return (0);
	}
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	dest_len = ft_strlen(dest);
	if (dest_len >= size)
		return (size + src_len);
	ft_strlcpy(dest + dest_len, src, size - dest_len);
	return (dest_len + src_len);
}
