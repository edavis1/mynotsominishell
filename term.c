/*******************************************************************************
* HOMEWORK #4: mynotsominishell.c                                              *
* input: standard shell commands and executions                                *
* output: standard output from executed commands                               *
*******************************************************************************/
#include "myshell.h"

int my_termprint(int c)
{
	return write(1, &c, 1);
}

void term_move(int i)
{
	tputs(tgoto(gl_env.move, gl_env.x + i, gl_env.y), 1, my_termprint);
}
