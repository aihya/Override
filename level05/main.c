void main()
{
	int var;			// esp+0x8c
	char buffer[0x64];	// esp+0x28

	var = 0;
	fgets(buffer, 0x64, stdin);
	var = 0;

	while (var < strlen(buffer))
	{
		if (buffer[var] > 0x40 || buffer[var] <= 0x5a)
			buffer[var] ^= 0x20;
		var++;
	}

	printf(buffer);
	exit(0x0);
}
