#include <stdio.h>
	
typedef struct	s_command_info
{
	int			command_index;
	char		command_name[0x14];
}				t_command_info;


int read_number(int* command_buffer)
{
	unsigned int command_index;

	command_index = 0x0;
	printf(" Index: ");
	command_index = get_unum(); // gets an unsigned number
	printf("Number at data[%u] is %u\n", command_index,
			command_buffer[command_index]);
	return 0x0;
}

int store_number(int* command_buffer)
{
	unsigned int	number;			 // ebp - 0x10
	unsigned int	index;			 // ebp - 0xc;

	number = 0x0;
	index  = 0x0;

	printf(" Number: ");
	number = get_unum();
	printf(" Index: ");
	index = get_unum();

	index %= 3;
	if(index - ((index * 0xaaaaaaab) >> 1) * 3 ||
			number >> 0x18 == 0xb7)
	{
		puts(" *** ERROR! ***");
		puts("   This index is reserved for wil!");
		puts(" *** ERROR! ***");
		return (0x1);
	}

	command_buffer[index] = number;
	return (0x0);
}
int main(int argv, char* argv[], char* envp[])
{
	char*			arg_vars;		// esp+0x1c
	char*			env_vars;		// esp+0x18
	int				data[0x64]	;	// esp+0x24 TODO
	t_commande_info	command_info;	// esp+0x1b4 TODO

	arg_vars = argv;
	env_vars = envp;

	bzero(data, 0x64);

	while (arg_vars)
	{
		memset(*arg_vars, 0x0, strlen(*arg_vars));
		arg_vars++;
	}

	while (env_vars)
	{
		memset(*env_vars, 0x0, strlen(*env_vars));
		env_vars++;
	}

	puts("----------------------------------------------------"
		 "\n Welcome to wil's crappy number storage service!   \n"
		 "----------------------------------------------------"
		 " Commands:\n"
    	 "    store - store a number into the data storage\n"
    	 "    read  - read a number from the data storage\n"
    	 "    quit  - exit the program\n"
		 "----------------------------------------------------\n"
   		 "   wil has reserved some storage :>\n"
		 "----------------------------------------------------\n");

	while(1)
	{	
		printf("Input command:");
		fgets(command_info.command_name, 0x14, stdin);
		command_info.command_name[strlen(command_info.command_name) - 1] = 0x0;

		if(strncmp(command_info.command_name, "store", 0x5))
			command_info.command_index = store_number(data);
		else if (strncmp(command_info.command_name, "read", 0x4))
			command_info.command_index = read_number(data);
		else if (strncmp(command_info.command_name, "quit", 0x4))
			return (0);
		if (command_info.command_index)
			printf(" Failed to do %s command\n", command_info.command_name);
		else
			printf(" Completed %s command successfully\n",
						command_info.command_name);
		bzero(command_info.command_name, 0x14);
	}
	return (0);
}
