#include <stdio.h>

void auth(char *login, unsigned int serial)
{
	int i;
	int	j;

	i = strcspn(login, "\n");
	login[i] = '\n';

	j = strnlen(login, 0x20);
	if (j)
	{
		if (j > 0x5)
		{
			ptrace(PTRACE_TRACEME, 0, 0x1, NULL);
		}
	}
}

int	main(int argc, char *argv[])
{
	
	return (0);
}
