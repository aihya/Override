#include <stdio.h>

char	a_user_name[96]; // 0x804a040

int	verify_user_name()
{
	puts("verifying username....\n");
	return (strncmp(a_user_name, "dat_wil", 0x7));
}

int verify_user_pass(buffer)
{
	return (strncmp(buffer, "admin", 0x5));
}

int main()
{
	int val;         // esp+0x5c
	char buffer[0x40]; // esp+0x1c

	bzero(buffer, 0x10);

	val = 0x0;
	puts("********* ADMIN LOGIN PROMPT *********");

	printf("Enter Username: ");
	fgets(a_user_name, 0x100, stdin);

	val = verify_user_name();
	
	if (val == 0x0)
	{
		puts("Enter password: ");
		fgets(buffer, 0x64, stdin);
		
		val = verify_user_pass(buffer);
		
		if (val == 0x0)
		{
			puts("nope, incorrect password...\n");
			return (0x1);
		}
		else if (val == 0x0)
			return (0);
	}
	else
	{
		puts("nope, incorrect username...\n");
		return (1);
	}

	return (0);
}
