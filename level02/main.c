#include <stdio.h>

int main()
{
	FILE*	fileptr;       // rbp-0x8
	int		read_count;    // rbp-0xc
	char	buffer1[0x64]; // rbp-0x70
	char	buffer2[0x30]; // rbp-0xa0
	char	buffer3[0x70]; // rbp-0x110

	bzero(buffer1, 0xc);
	bzero(buffer2, 0x5);
	bzero(buffer3, 0xc);

	fileptr = NULL;
	int_var = 0x0;

	fileptr = fopen("/home/users/level03/.pass", "r");
	if (fileptr == NULL)
	{
		fwrite("ERROR: failed to open password file\n", 0x1, 0x24, stderr);
		exit(0x1);
	}

	read_count = fread(buffer2, 0x1, 0x29, fileptr);
	buffer2[strcspn(buffer2, "\n")] = '\0';

	if (read_count != 0x29)
	{
		fwrite("ERROR: failed to read password file\n", 0x1, 0x24, stderr);
		fwrite("ERROR: failed to read password file\n", 0x1, 0x24, stderr);
		exit(0x1);
	}

	fclose(fileptr);

	puts("===== [ Secure Access System v1.0 ] =====");
	puts("/***************************************\\");
	puts("| You must login to access this system. |");
	puts("\\**************************************/");

	printf("--[ Username: ");

	fgets(buffer1, 0x64, stdin);

	
	return (0);
}

/*
rip
rbp





buffer1 rbp - 0x70




buffer2 rbp - 0xa0



*/
