/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 11:59:51 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/07/10 20:09:01 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>

int	ft_memcmp(const void *src1, const void *src2, size_t n)
{
	const unsigned char	*s1;
	const unsigned char	*s2;

	if (src1 == NULL || src2 == NULL || n == 0)
	{
		errno = EINVAL;
		return (0);
	}
	s1 = (const unsigned char *)src1;
	s2 = (const unsigned char *)src2;
	while (n--)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}
