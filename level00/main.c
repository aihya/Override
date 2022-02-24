#include <stdio.h>

int main()
{
	int	val;

	puts("***********************************");
	puts("* \t     -Level00 -\t\t  *");
	puts("***********************************");
	printf("Password:");

	scanf("%d", &val);

	if (val == 0x149c)
	{
		puts("\nAuthenticated!");
		system("/bin/sh");
		return (0);
	}
	return (1);
}
