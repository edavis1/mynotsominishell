/*******************************************************************************
* HOMEWORK #4: mynotsominishell.c                                              *
* input: standard shell commands and executions                                *
* output: standard output from executed commands                               *
*******************************************************************************/
#include "myshell.h"

void exitShell()
{
	saveHistory();
	free(gl_env.history);
	
	// Restore I/O
	ioctl(0, TCSETA, &(gl_env.line_backup));
	dup2(gl_env.stdio_backup, 1);

	my_str("Thank you for using my not-so-mini shell.\n");
	exit(0);
}


void initShell()
{
	int fd;
	char* name;
	char* term;
	static char bp[2048];
	struct termio line;
	
	gl_env.cmd = (char*)xmalloc(MAX_CMD_LENGTH * sizeof(char));
	gl_env.cmdlength = 0;	
	gl_env.history = (char**)xmalloc(MAX_HISTORY_SIZE * sizeof(char*));
	gl_env.index = 0;
	getHistory();

	name = ttyname(0);
	fd = open(name, O_WRONLY);
	gl_env.stdio_backup = dup(1);
	dup2(fd, 1);
	
	if ((term = getenv("TERM")) == 0)
		my_str("ERROR: Terminal type not defined.\n");

	if (tgetent(bp, term) < 0)
		my_str("ERROR: Could not access termcap database.\n");
	
	initCaps();
	
	ioctl(0, TCGETA, &line);
	gl_env.line_backup = line;
	line.c_cc[VMIN] = READMIN;
	line.c_cc[VTIME] = READTIME;
	line.c_lflag &= ~(ICANON|ECHO|ISIG);
	ioctl(0, TCSETA, &line);
}


void getHistory()
{
	FILE* fp;
	int i;
	
	if ((fp = fopen(".history", "r")) == NULL)
		my_str("No history found.\n");
	else
	{
		i = 0;
		while (1)
		{
			gl_env.history[i] = (char*)xmalloc(MAX_CMD_LENGTH * sizeof(char));
			if (fgets(gl_env.history[i++], MAX_CMD_LENGTH-1, fp) == NULL)
				break;
		//	my_str(gl_env.history[i - 1]);
		}
		gl_env.ncmds = i - 1;
	}
	fclose(fp);
}


void saveHistory()
{
	FILE* fp;
	int i;
	if ((fp = fopen(".history", "w")) == NULL)
		my_str("Error saving history.\n");
	else
	{
		i = 0;
		while(gl_env.history[i] != NULL)
		{
		//	my_str(gl_env.history[i]);
			fputs(gl_env.history[i++], fp);			
		}
	}
}


void addCommand(char* cmd)
{
	int i;
	
	if (gl_env.ncmds < MAX_HISTORY_SIZE)
		gl_env.history[gl_env.ncmds++] = my_strdup(cmd);
	else
	{
		free(gl_env.history[0]);
		for (i = 1; i < MAX_HISTORY_SIZE; i++)
			gl_env.history[i - 1] = gl_env.history[i];
		gl_env.history[MAX_HISTORY_SIZE - 1] = my_strdup(cmd);
	}
}
