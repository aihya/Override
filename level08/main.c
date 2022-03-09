#include <stdio.h>

//               rbp-0x118       rbp-0x120         rbp-0x128
//               rdi             rsi               rdx
void log_wrapper(FILE backup_fd, char *somestring, char *filename)
{
	char	buffer[0x110];	// rbp-0x110

	strcpy(buffer, somestring);
	snprintf(buffer + strlen(buffer), 0xfe - strlen(buffer), filename);
	buffer[strcspn(buffer, "\n")] = 0x0;
	fprintf(backup_fd, "LOG: %s\n", buffer);
}

void main(int argc, char *argv[])
{
	char	**args;			// rbp-0xa0
	int		args_count;		// rbp-0x94
	FILE	log_fd;			// rbp-0x88
	FILE	file_fd;		// rbp-0x80
	int		backups_fd		// rbp-0x78
	char	c;				// rbp-0x71
	char	buffer[0x30];	// rbp-0x70

	if (args_count != 2) 
		printf("Usage: %s filename\n");

	log_fd = fopen("./backups/.log", 'w');
	if (log_fd == 0)
	{
		printf("ERROR: Failed to open %s\n", "./backups/.log");
		exit(0x1);
	}

	log_wrapper(log_fd, "Starting back up: ", args[1]);

	file_fd = fopen(args[1], 'r');
	if (file_fd == 0)
	{
		printf("ERROR: Failed to open %s\n", args[1]);
		exit(0x1);
	}

	strcpy(buffer, "./backups/");	// TODO: to reconsider: 0x00400b09
	strncat(buffer, args[1], 0x63 - strlen(buffer));

	backups_fd = open(buffer, 0xc1, 0x1b0);
	if (backups_fd < 0)
	{
		printf ("ERROR: Failed to open %s%s\n", "./backups/", args[1]);
		exit(0x1);
	}

	while ((c = fgetc(file_fd)) != 0xff)
		write(backups_fd, c, 0x1);

	log_wrapper(log_fd, "Finished back up ", args[1]);

	fclose(file_fd);
	close(backups_fd);
}
