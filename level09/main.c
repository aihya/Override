#include <stdio.h>

typedef struct	s_msg_struct
{
	int		message_size;
	char	message[0x8c];
	char	username[0x28];
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
	strncpy(message->message, msg, message->message_size);
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
		message->username[count] = username[count];
		count++;
	}

	printf(">: Welcome, %s", message->username);
}


void handle_msg()
{
	t_msg_struct msg_struct;

	bzero(msg_struct.username, 0x28);
	msg_struct.message_size = 0x8c;
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
