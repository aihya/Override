#include <stdio.h>

char	a_user_name[0x100];

void	verify_user_name()
{
	puts("verifying username....\n");

	return (strncmp(a_user_name, "dat_wil", 0x7));
}

void	verify_user_pass(char *main_buffer)
{
	return (strncmp(main_buffer, "admin", 0x5));
}

int main()
{
	char	buffer[64];	// esp + 0x1c
	int		diff;		// esp + 0x5c

	bzero(buffer, 0x10);
	diff = 0;

	puts("********* ADMIN LOGIN PROMPT *********");
	printf("Enter Username: ");

	fgets(a_user_name, 0x100, stdin);
	diff = verify_user_name();
	if (diff != 0x0)
	{
		puts("nope, incorrect username...\n");
		return (1);
	}

	puts("Enter Password: ");
	fgets(buffer, 0x64, stdin);

	diff = verify_user_pass(buffer);
	if (diff != 0x0)
	{
		puts("nope, incorrect password...\n");
		return (1);
	}

	return (0);
}
