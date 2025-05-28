/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 12:33:06 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/05/28 12:34:18 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	srcsize;

	srcsize = ft_strlen(src);
	if (!destsize)
		return (srcsize);
	while (*src && destsize > 1)
	{
		*dest = *src;
		dest++;
		src++;
		destsize--;
	}
	*dest = '\0';
	return (srcsize);
}
