#include<stdio.h>

int auth(char *login, unsigned int serial)
{
	unsigned int	login_len;			// ebp - 0xc
	unsigned int	login_hash;			// ebp - 0x10
	int		counter;			// ebp - 0x14

	login[strcspn(login, "\n")] = 0x0;
	login_len = strnlen(login, 0x20);
	// security check

	if(login_len <= 0x5)
		return (0x1);

	if(ptrace(PTRACE_TRACEME, 0x1, NULL, NULL) == -1)
	{
		puts("\033[32m.---------------------------.");
		puts("\033[31m| !! TAMPERING DETECTED !!  |");
		puts("\033[32m'---------------------------'");
		return(0x1);
	}

	login_hash = (*(login + 3) ^ 0x1337) + 0x5eeded; 
	counter = 0x0;
	while (counter < login_len)
	{
		if (login[counter] <= 0x1f)
			return (0x1);
		login_hash += ((login[counter]  ^ login_hash)
			- (((login_hash - ((login[counter]  ^ login_hash) * 0x88233b2b)) << 1)
			+ ((login[counter]  ^ login_hash) * 0x88233b2b)) << 0xa) * 0x539;
		counter++;
	}
	if(serial == login_hash)
		return (0x0);
	return (0x1);
}

int main(int argc, char **argv)
{
	// stack corruption setup
	unsigned int	serial_number;		// esp + 0x28
	char		login_buffer[36];	// esp + 0x2c

	puts("***********************************");
	puts("*\t\tlevel06\t\t  *");
	puts("***********************************");
	printf("-> Enter Login: ");
	fgets(login_buffer, 0x20, stdin);

	puts("***********************************");
	puts("***** NEW ACCOUNT DETECTED ********");
	puts("***********************************");
	printf("-> Enter Serial: ");
	scanf("%u", &serial_number);

	if(auth(login_buffer, serial_number) == 0x0)
	{
		puts("Authenticated!");
		system("/bin/sh");
		// stack corruption check
		return (0x0);
	}
	// stack corruption check
	return (0x1);
}
