/*******************************************************************************
* HOMEWORK #4: mynotsominishell.c                                              *
* input: standard shell commands and executions                                *
* output: standard output from executed commands                               *
*******************************************************************************/
#include "myshell.h"

void initCaps()
{
	gl_env.up = term_get_cap(UP);
	gl_env.down = term_get_cap(DOWN);
	gl_env.move = term_get_cap(MOVE);
	gl_env.insert = term_get_cap(INSERT);
	gl_env.end_insert = term_get_cap(END_INSERT);
	gl_env.delete_line = term_get_cap(DELETE_LINE);
	gl_env.delete_char = term_get_cap(DELETE_CHAR);
	gl_env.left = term_get_cap(LEFT);
	gl_env.right = term_get_cap(RIGHT);
//	gl_env.del_mode = term_get_cap(DEL_MODE);
//	gl_env.end_del_mode = term_get_cap(END_DEL_MODE);

}
	
char* term_get_cap(char* cap)
{
	static char area[2048];
	char* str;
	
	if ((str = tgetstr(cap, (char**)&area)) == NULL)
	{
		my_str("ERROR: Invalid capability call. ");
		my_str(cap);
		my_str("\n");
	}
	return str;
}

void get_win_size()
{
	ioctl(0, TIOCGWINSZ, &(gl_env.win));
}
