NAME	= myshell
SRC	= main.c init.c input.c caps.c ctrl.c term.c
OBJ	= $(SRC:.c=.o)
RM	= rm -f
LIBLOC	= ../lib
LIB	= -ltermcap -lmy
CFLAGS	= -I$(LIB)
DEFS	= -DDEBUG

#
#
all	: $(OBJ)
	-$(RM) $(NAME)
	cc -L$(LIBLOC) $(SRC) $(LIB) -o $(NAME)
		
debug	: $(OBJ)
	-$(RM) $(NAME)
	cc -L$(LIBLOC) $(SRC) -lmy $(DEFS) -o $(NAME)

clean	:
	-$(RM) *.o
	-$(RM) *~
	-$(RM) \#*

fclean	: clean
	-$(RM) $(NAME)

re: fclean all
