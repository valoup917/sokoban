##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## .
##

CC = gcc

SRC =	src/free.c 		\
		src/my_game.c 	\
		src/loose.c		\
		src/manage_o.c 	\
		src/count_my_o.c 	\
		src/win.c 		\
		src/helper.c 	\
		src/map_management.c 	\
		src/my_movement1.c 	\
		src/my_movement2.c 	\
		src/p_management.c 	\
		lib/my_str_to_word_array.c		\
		lib/my_strlen.c 	\
		lib/my_putchar.c 	\
		lib/my_putstr.c 	\

SRC_MAIN = src/main.c

TEST = tests/test_sokoban.c

OBJ = $(SRC:.c=.o)

OBJ_MAIN = $(SRC_MAIN:.c=.o)

TEST_OBJ = $(TEST:.c=.o)

CFLAGS = -Wall -Wextra -pedantic -pg

CPPFLAGS = -I./include

LDFLAGS = -lncurses

NAME = my_sokoban

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_MAIN)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJ) $(OBJ_MAIN)
	@       tput setaf 1; cat include/art; tput sgr0

clean:
	rm -f $(OBJ) $(OBJ_MAIN)

fclean:	clean
	rm -f *gmon*
	rm -f $(NAME)
	rm -f unit_tests
	rm -f $(TEST_OBJ)
	rm -f *.gc*
	rm -f src/*.gc*
	rm -f tests/*.gc*
	rm -f *~
	rm -f *#
	rm -f src/*~
	rm -f src/*#

re: fclean all

.PHONY: all clean fclean re tests_run