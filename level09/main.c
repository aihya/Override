#include <stdio.h>

typedef struct	s_msg_struct
{
	int		var;
	char	msg[0xb4];
}				t_msg_struct;

void secret_backdoor()
{
	char	buffer[0x80];

	fgets(buffer, 0x80, stdin);
	system(buffer);
}

void set_msg(t_msg_struct* message)
{
	char	msg[0x400];

	bzero(msg, 0x80);
	puts(">: Msg @Unix-Dude");
	printf(">>: ");

	fgets(msg, 0x400, stdin);
	strncpy(message->msg, msg, message->var);
}

void set_username(t_msg_struct *message)
{
	int count;				// rbp-0x4
	char username[0x90];	// rbp-0x90

	bzero(username, 0x10);
	puts(">: Enter your username");
	printf(">>: ");

	fgets(username, 0x80, stdin);

	count = 0;
	while (count <= 0x28 && username[count])
	{
		message->msg[count + 0x8c] = username[count];
		count++;
	}

	printf(">: Welcome, %s", message->msg + 0x8c);
}


void handle_msg()
{
	t_msg_struct msg_struct;

	bzero(msg_struct.msg + 0x8c, 0x28);
	msg_struct.var = 0x8c;
	set_username(&msg_struct);
	set_msg(&msg_struct);
	puts(">: Msg sent!");
}

int main()
{
	puts("--------------------------------------------"
		 "\n|   ~Welcome to l33t-m$n ~    v1337        |\n"
		 "--------------------------------------------");
	handle_msg();

	return (0);
}
