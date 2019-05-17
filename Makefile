##
## Makefile for wolf3d in /home/djerad_k/Desktop/Igraph/Wolf3d/MUL_2014_wolf3d
## 
## Made by kevin Djeradi
## Login   <djerad_k@epitech.net>
## 
## Started on  Tue Dec 23 13:25:34 2014 kevin Djeradi
## Last update Sun Jan  4 21:20:55 2015 kevin Djeradi
##

NAME	= wolf3d

SRC	= puts.c \
	  init.c \
	  movements.c \
	  show.c

OBJ	= $(SRC:.c=.o)

LIB	= -L/usr/lib64/X11 -lX11 -lXext -L/usr/lib64/ -lmlx -lm

all	: $(NAME)

$(NAME)	: $(OBJ)
	  @cc -o $(NAME) $(OBJ) $(LIB)
	@echo -e "\e[0;5;38m██╗    ██╗ ██████╗ ██╗     ███████╗\e[0;5;36m    ██████╗ ██████╗ ";
	@echo -e "\e[0;5;38m██║    ██║██╔═══██╗██║     ██╔════╝   \e[0;5;36m ╚════██╗██╔══██╗";
	@echo -e "\e[0;5;38m██║ █╗ ██║██║   ██║██║     █████╗     \e[0;5;36m  █████╔╝██║  ██║";
	@echo -e "\e[0;5;33m██║███╗██║██║   ██║██║     ██╔══╝     \e[0;5;38m  ╚═══██╗██║  ██║";
	@echo -e "\e[0;5;33m╚███╔███╔╝╚██████╔╝███████╗██║        \e[0;5;38m ██████╔╝██████╔╝";
	@echo -e "\e[0;5;33m ╚══╝╚══╝  ╚═════╝ ╚══════╝╚═╝        \e[0;5;38m ╚═════╝ ╚═════╝ ";
	@echo -e "                                                      \e[00;39m";

$(OBJ)	:
	  @cc -c $(SRC)

clean	:
	  @echo "Les fichiers ont été supprimés avec succès";
	  @rm -rf $(OBJ)

fclean	: clean
	  @echo "L'executable a été supprimé avec succès";
	  @rm -rf $(NAME)

re	: fclean all
