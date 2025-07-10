# 🧠 Libft Save — Safe Libft Implementation with Memory Management & errno Support
## 📚 Overview

This project is an enhanced version of the classic libft, designed for Codam/42 students who want to write safer and more maintainable C code.

Key features include:

- ✅ Automatic memory tracking and cleanup
- ⚠️ Error handling with errno setting (e.g., ENOMEM, EINVAL)
- 💥 A handy ft_panic() function for error reporting and safe program termination

The goal is to prevent memory leaks, simplify error handling, and improve code robustness during development.

## 🚀 Example Usage
```c
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

	dest = ft_malloc(100); // Like malloc, but with tracking
	if (dest == NULL)
		ft_panic(strerror(errno));

	ft_strlcpy(dest, NULL, 100); // Triggers an error, errno will be set

	if (errno)
		ft_panic(strerror(errno));

	ft_destroy(); // Frees all tracked memory
	return (0);
}
```

## 🛠 Core Features
Function	Description
- **ft_malloc(size)** — Wrapper around malloc() with internal tracking  
- **ft_substr(...)** — Safe substring function with errno support  
- **ft_itoa(...)** — Integer to string conversion with memory error checking  
- **ft_strlcpy(...)** — Safe string copy, validates inputs and sets errno  
- **ft_strtol(...)** — Safe string-to-long conversion with error checking and errno support  
- **ft_destroy()** — Frees all memory allocated via ft_malloc()  
- **ft_panic(msg)** — Prints an error message and exits with EXIT_FAILURE  

## 🧼 Memory Management
All allocations made using ft_malloc() are tracked internally. When you're done, just call ft_destroy() to automatically free everything, ensuring:
- No memory leaks
- Clean error exits
- Better code hygiene during development

## 🔥 Error Handling
Functions are defensive and set errno on failure:
- Invalid arguments → errno = EINVAL
- Memory allocation failure → errno = ENOMEM
- Other common cases handled in a POSIX-compliant way

You can check errno after any function call or use ft_panic() for immediate termination.
