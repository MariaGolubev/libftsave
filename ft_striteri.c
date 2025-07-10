/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 12:27:10 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/07/10 20:20:55 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>

void	ft_striteri(char *str, void (*fn)(unsigned int, char *))
{
	size_t	pos;

	if (str == NULL || fn == NULL)
	{
		errno = EINVAL;
		return ;
	}
	pos = 0;
	while (str[pos] != '\0')
	{
		fn((unsigned int)pos, &str[pos]);
		pos++;
	}
}
