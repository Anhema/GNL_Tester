#!/bin/sh
ROUTE="../"

SRC=""$ROUTE"get_next_line.c "$ROUTE"get_next_line_utils.c "$ROUTE"get_next_line.h"
MAIN="main.c main_utils.c expected.c leaks_cheker.c utils.h"
BUFFER=-1
GNL_PATH=$ROUTE"get_next_line.c"
COM="gcc -Wall -Werror -Wextra -D BUFFER_SIZE=$BUFFER -g3"
NAME="TEST_RESULT"

BOLD="\033[1m"
UNDERLINE="\033[4m"

BLACK="\033[30m"
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
BLUE="\033[34m"
PURPLE="\033[35m"
CYAN="\033[36m"
WHITE="\033[37m"
DEFAULT="\033[m"

printf $BLUE"NORMINETTE = "$DEFAULT
NORME_VAR=$(norminette "$ROUTE"get_next_line.c "$ROUTE"get_next_line_utils.c "$ROUTE"get_next_line.h 2>&1)
if echo "$NORME_VAR" | grep -q command
then
	printf "not found"
	printf "\norminette : command not found\n\n"
elif echo "$NORME_VAR" | grep -qE '(Error|Warning)'
then
	printf $RED"check failed "$DEFAULT
	echo "$NORME_VAR" | grep -E '(Error|Warning)'
	printf $RED"Norme check failed\n"$DEFAULT
	retvalue=0
else
	printf $GREEN"OK\n"$DEFAULT
fi

run()
{
	#rm $NAME
	$COM $MAIN $SRC
	rm -r a.out.dSYM
	mv a.out $NAME
	./$NAME files/no_file files/empty files/10_lines files/4_lines_end_with_newline files/start_with_newline files/big_line files/10_big_lines file/only_newlines files/20_lines
}

#gcc -Wall -Werror -Wextra -D BUFFER_SIZE=42 -g3 $(ROUTE)get_next_line.c $(ROUTE)get_next_line_utils.c $(ROUTE)get_next_line.h main.c main.c utils.h main_utils.c
run

BUFFER=1
COM="gcc -Wall -Werror -Wextra -D BUFFER_SIZE=$BUFFER -g3"

run

BUFFER=42
COM="gcc -Wall -Werror -Wextra -D BUFFER_SIZE=$BUFFER -g3"

run

BUFFER=100000
COM="gcc -Wall -Werror -Wextra -D BUFFER_SIZE=$BUFFER -g3"

run