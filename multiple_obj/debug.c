#include "basic.h"

void	debug(void)
{
	int	fd;

	if (IMPLEMENT_DEBUG != 1)
		return ;
	fd = open("log_file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		exit(0);
	dup2(fd, STDOUT_FILENO);
	close(fd);
}
