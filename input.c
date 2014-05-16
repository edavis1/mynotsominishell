/*******************************************************************************
* HOMEWORK #4: mynotsominishell.c                                              *
* input: standard shell commands and executions                                *
* output: standard output from executed commands                               *
*******************************************************************************/
#include "myshell.h"

void getInput()
{
	char buffer[BUF_SZ];
	int n;
	
	my_str(PROMPT);
	
	while(1)
	{
		n = read(0, buffer, BUF_SZ - 1);
		check_char(buffer);
	}
}

void check_char(char* feed)
{
	int i;
	char* output;
	
	switch (feed[0])
	{
		case 1:
		//	my_str("Ctrl+A pressed.\n");
			ctrlA();
			break;
		case 3: 
		//	my_str("Ctrl+C pressed.\n");
			ctrlC();
			break;
		case 5: 
		//	my_str("Ctrl+E pressed.\n"); 
			ctrlE(); 
			break;
		case 11:
		//	my_str("Ctrl+K pressed.\n");
			ctrlK();
			break;
		case 12:
		//	my_str("Ctrl+L pressed.\n");
			ctrlL();
			break;
		case 25:
		//	my_str("Ctrl+Y pressed.\n");
			ctrlY();
			break;
		case 27:
			switch (feed[2])
			{
				case 'B':
				//	my_str("Down arrow pressed.\n");
					down();
					break;
                        	case 'A':
				//	my_str("Up arrow pressed.\n");
					up();
					break;
                        	case 'D':
				//	my_str("Left arrow pressed.\n");
					left();
					break;
                        	case 'C':
				//	my_str("Right arrow pressed.\n");
					right();
					break;
			} break;
		case 8:
		//	my_str("Backspace pressed.\n");
			backspace();
			break;
		case 10:
		//	my_str("Enter pressed.\n");
			enter();
			break;
		case 127:
		//	my_str("Delete pressed.\n");
			backspace();
			break;
		default:
			my_char(feed[0]);
			gl_env.cmd[gl_env.cmdlength++] = feed[0];	
			gl_env.x++;
			break;
	}
}
