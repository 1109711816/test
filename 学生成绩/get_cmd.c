#include <stdio.h>
#include <getch.h>
#include "get_cmd.h"

char get_cmd(char start,char end)
{
	while(1)
	{
		char cmd;
		cmd = getch();
		if(cmd >= start && cmd <= end)
		{
			printf("%c\n",cmd);
			return cmd;
		}
	}
}
