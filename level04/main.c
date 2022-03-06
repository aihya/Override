#include <stdio.h>

int main()
{
	long	ptrace_status;	// esp+0xa8
	int		pid;			// esp+0xac
	char	buf[136];		// esp+0x20
	int		status;			// esp+0x1c

	pid = fork();

	memset(buf, 0, 32);
	status = 0;

	if (pid != 0) // Parent
	{
		while (true)
		{
			wait(&status);
			if (status == 0) // Child exited
				break ;
			else if (status < 0)
			{
				ptrace_status = ptrace(0x3, pid, 0x2c, 0x0);
				if (ptrace_status != 0xb)
					continue ;
				puts("No exec...\n");
				kill(pid, SIGKILL);
			}
		}
		puts("child is exiting...\n");
	}
	else // Child
	{
		// Causes the child to recieve a SIGHUP signal when the parent is terminated.
		prctl(PR_SET_PDEATHSIG, 0x1);

		// Binds the child and the parent
		// (Only if the child was terminated before the parent).
		ptrace(PTRACE_TRACEME, 0, NULL, NULL);

		puts("Give me blabla...\n");
		gets(buf);
	}
	return (0);
}
