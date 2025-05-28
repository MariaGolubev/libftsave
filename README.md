# libftsave

```c
#include "libft.h"
#include <sys/wait.h>

int main(void)
{

	char *str = "Hello, World!";

	char *substr = ft_substr(str, 7, 5);
	if (substr == NULL)
		ft_panic("Memory allocation failed");
	
	ft_putendl_fd(substr, STDOUT_FILENO);

	pid_t pid = fork();
	if (pid < 0)
		ft_panic("Fork failed");

	if (pid == 0) {
		ft_putendl_fd("Child process executing...", STDOUT_FILENO);
		char *child_result = ft_strjoin(substr, " - Child");
		if (child_result == NULL)
			ft_panic("Memory allocation failed in child process");
		ft_putendl_fd(child_result, STDOUT_FILENO);
		ft_free(child_result);
		ft_exit(0);
	}

	if (waitpid(pid, NULL, 0) < 0)
		ft_panic("Waitpid failed");

	ft_free(substr);
	return 0;
}
```