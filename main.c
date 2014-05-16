/*******************************************************************************
* HOMEWORK #4: mynotsominishell.c                                              *
* input: standard shell commands and executions                                *
* output: standard output from executed commands                               *
*******************************************************************************/
#include "myshell.h"

int main(int argc, char *argv[])
{
	initShell();	
	getInput();
	exitShell();
}
