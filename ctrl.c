/*******************************************************************************
* HOMEWORK #4: mynotsominishell.c                                              *
* input: standard shell commands and executions                                *
* output: standard output from executed commands                               *
*******************************************************************************/
#include "myshell.h"

void ctrlA()
{

}

void ctrlC()
{
	exitShell();
}

void ctrlE()
{

}

void ctrlK()
{

}

void ctrlL()
{

}

void ctrlY()
{

}

void backspace()
{
	tputs(gl_env.del_mode, 1, my_termprint);
	if (gl_env.x > 0)
	{	
		tputs(gl_env.left, 1, my_termprint);
		tputs(gl_env.delete_char, 1, my_termprint);	
		gl_env.x--;
		gl_env.cmdlength--;
	}
	tputs(gl_env.end_del_mode, 1, my_termprint);
}

void enter()
{
	char** v;
	pid_t pid;
	int i;

	gl_env.cmd[gl_env.cmdlength] = '\0';	
	my_char('\n');

	if (!my_strncmp(gl_env.cmd, "exit", 4))
		exitShell();
	if (!my_strncmp(gl_env.cmd, "history", 7))
	{
		for (i = 0; i < gl_env.ncmds; i++)
			my_str(gl_env.history[i]);
	}		
	v = my_str2vect(gl_env.cmd);
	
	if (!my_strcmp(*v, "cd"))
		chdir(v[1]);
	else 
	{
		if ((pid = fork()) < 0)
			exit(0);
		if (pid > 0)
			wait();
		else
		{
			if (execvp(v[0], v) < 0)
				my_str("Command not found.\n");
			exit(0);
		}
	}
	
	addCommand(my_strconcat(gl_env.cmd, "\n"));
	my_strcpy(gl_env.cmd, "");
	gl_env.cmdlength = 0;
	gl_env.x = 0;
	my_str(PROMPT);	

	my_str(gl_env.cmd);
}

void up()
{
	if (gl_env.index < gl_env.ncmds)
	{
		tputs(gl_env.delete_line, 1, my_termprint);
		my_str(PROMPT);
		gl_env.index++;
		gl_env.cmd = gl_env.history[gl_env.index];
		my_str(gl_env.cmd);
	}
}

void down()
{
	if (gl_env.index > 0)
	{
		tputs(gl_env.delete_line, 1, my_termprint);
		my_str(PROMPT);
		gl_env.index--;
		gl_env.cmd = gl_env.history[gl_env.index];
		my_str(gl_env.cmd);
	}
}

void left()
{
	if (gl_env.x > 0)
	{
		tputs(gl_env.left, 1, my_termprint);
		gl_env.x--;
	}		
}

void right()
{
	if (gl_env.x < gl_env.cmdlength)
	{
		tputs(gl_env.right, 1, my_termprint);
		gl_env.x++;
	}
}
