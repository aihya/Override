#include <stdio.h>

void decrypt(int diff)
{
	// CANARY STUFF

	char buff[0x10] = "Q}|u`sfg~sf{}|a3"; // ebp-0x1d
	int buff_size;	// ebp-0x24
	int var;		// ebp-0x28

	buff_size = strlen(buff);
	var = 0x0;
	while (var < buff_size)
	{
		buff[var] ^= diff;
		var++;
	}
	if (strncmp(buff, "Congratulations!", 0x11))
		system("/bin/sh");
	else
		puts("\nInvalid Password");

	// CANARY CHECK
}

void test(int var, int something)
{
	int diff = var - something;

	if (diff < 0x15)
	{
		switch (diff)
		{
			case 0:
				decrypt(diff);
				break;
			case 1:
				decrypt(diff);
				break;
			case 2:
				decrypt(diff);
				break;
			case 3:
				decrypt(diff);
				break;
			case 4:
				decrypt(diff);
				break;
			case 5:
				decrypt(diff);
				break;
			case 6:
				decrypt(diff);
				break;
			case 7:
				decrypt(diff);
				break;
			case 8:
				decrypt(diff);
				break;
			case 9:
				decrypt(diff);
				break;
			case 10:
				decrypt(diff);
				break;
			case 11:
				decrypt(diff);
				break;
			case 12:
				decrypt(diff);
				break;
			case 13:
				decrypt(diff);
				break;
			case 14:
				decrypt(diff);
				break;
		}
	}
	else
		decrypt(rand());
}

int main()
{
	int	var;

	srand(time(0x0));

	puts("***********************************");
	puts("*\t\tlevel03\t\t**");
	puts("***********************************");

	printf("Password: ");

	scanf("%d", &var);

	test(var, 0x1337d00d);

	return (0x0);
}
