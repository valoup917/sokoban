##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## .
##

SRC		=	src/main.c		\
			src/window2.c 	\
			src/loose.c		\
			src/manage_o.c 	\
			src/win.c 		\
			src/final_score.c 	\
			src/helper.c 	\
			src/map_management.c 	\
			src/print_map_x.c 	\
			src/my_movement1.c 	\
			src/my_movement2.c 	\
			src/p_management.c 	\
			src/menu.c 		\
			src/menu2.c 	\
			lib/my_str_to_word_array.c		\
			lib/my_strlen.c 	\
			lib/my_putchar.c 	\
			lib/my_putstr.c 	\

NAME	=	my_sokoban

all:
	gcc -o $(NAME) $(SRC) -lncurses -lcsfml-audio -g3 -Wall -Wextra
	@       tput setaf 1; cat include/art; tput sgr0

clean:
		rm -f src/*~
		rm -f src/\#*\#
		rm -f include/*~
		rm -f include/\#*\#

fclean: clean
		rm -f $(NAME)

re: fclean all