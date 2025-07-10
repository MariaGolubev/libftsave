/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   example.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/10 20:52:32 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/07/10 21:08:58 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>
#include <string.h>

int	main(void)
{
	char	*str;
	char	*number_str;
	char	*dest;

	str = ft_substr("Hello, World!", 7, 5);
	if (str == NULL)
		ft_panic(strerror(errno));
	ft_putendl_fd(str, STDOUT_FILENO);
	number_str = ft_itoa(42);
	if (number_str == NULL)
		ft_panic(strerror(errno));
	dest = ft_malloc(100);
	if (dest == NULL)
		ft_panic(strerror(errno));
	ft_strlcpy(dest, NULL, 100);
	if (errno)
		ft_panic(strerror(errno));
	ft_destroy();
	return (0);
}
