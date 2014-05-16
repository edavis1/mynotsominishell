/*******************************************************************************
* HOMEWORK #4: mynotsominishell.h                                              *
* input: standard shell commands and executions                                *
* output: standard output from executed commands                               *
*******************************************************************************/
#ifndef _MYNOTSOMINISHELL_H_
#define _MYNOTSOMINISHELL_H_

#ifndef NULL
#define NULL ((void*)0)
#endif

#include <termcap.h>
#include "../lib/my.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/termios.h>
#include <signal.h>
#include <unistd.h>

#define READTIME 1
#define READMIN 3
#define BUF_SZ 256

#define UP "ku"
#define DOWN "kd"
#define MOVE "cm"
#define INSERT "im"
#define END_INSERT "ei"
#define DELETE_LINE "dl"
#define LEFT "le"
#define RIGHT "nd"
#define DELETE_CHAR "dc"
#define DEL_MODE "dm"
#define END_DEL_MODE "ed"
#define INSERT_CHAR "ic"

#define MAX_HISTORY_SIZE 100
#define MAX_CMD_LENGTH 256

#define PROMPT "$>"

struct s_env
{
	char*	up;
	char*	down;
	char*	move;
	char*	insert;
	char*	end_insert;
	char*	delete_line;
	char*	left;
	char*	right;
	char*	delete_char;
	char*	del_mode;
	char*	end_del_mode;
	char*	insert_char;
	struct winsize win;
	struct termio line_backup;
	int	stdio_backup;
	char*	cmd;
	int	x;
	int	y;
	int 	cmdlength;
	char**	history;
	int	ncmds;
	int	index;
} 	gl_env;

void exitShell();
void initShell();
void getHistory();
void saveHistory();
void addCommand();

void getInput();
void check_char(char*);

char* term_get_cap(char*);
void initCaps();
void get_win_size();

int my_termprint(int);
void term_move(int);

void ctrlA();
void ctrlE();
void ctrlK();
void ctrlL();
void ctrlY();
void backspace();
void enter();
void up();
void down();
void left();
void right();
#endif
