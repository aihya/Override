#include <stdio.h>

//               rbp-0x118       rbp-0x120         rbp-0x128
//               rdi             rsi               rdx
void log_wrapper(FILE *dst_fd, char *header, char *filename)
{
	char	buffer[0x110];	// rbp-0x110

	strcpy(buffer, header);
	snprintf(buffer + strlen(buffer), 0xfe - strlen(buffer), filename);
	buffer[strcspn(buffer, "\n")] = 0x0;
	fprintf(dst_fd, "LOG: %s\n", buffer);
}

void main(int argc, char *argv[])
{
	char	buffer[0x30];	// rbp-0x70
	char	c;				// rbp-0x71
	int		dst_fd;			// rbp-0x78
	FILE	*src_fd;		// rbp-0x80
	FILE	*log_fd;		// rbp-0x88
	int		args_count;		// rbp-0x94
	char	**args;			// rbp-0xa0
	int		counter;		// rbp-0xa8

	// These two lines are sus, they might not be invoked explicitly.
	args_count = argc;
	args = argv;

	if (args_count != 2) 
		printf("Usage: %s filename\n", args[0]);

	log_fd = fopen("./backups/.log", 'w');
	if (log_fd == 0)
	{
		printf("ERROR: Failed to open %s\n", "./backups/.log");
		exit(0x1);
	}

	log_wrapper(log_fd, "Starting back up: ", args[1]);

	src_fd = fopen(args[1], 'r');
	if (src_fd == 0)
	{
		printf("ERROR: Failed to open %s\n", args[1]);
		exit(0x1);
	}

	strcpy(buffer, "./backups/");	// TODO: to reconsider: 0x0000000000400b09
	strncat(buffer, args[1], 0x63 - strlen(buffer));

	dst_fd = open(buffer, 0xc1, 0x1b0);
	if (dst_fd < 0)
	{
		printf("ERROR: Failed to open %s%s\n", "./backups/", args[1]);
		exit(0x1);
	}

	while ((c = fgetc(src_fd)) != 0xff)
		write(dst_fd, c, 0x1);

	log_wrapper(log_fd, "Finished back up ", args[1]);

	fclose(src_fd);
	close(dst_fd);
}
