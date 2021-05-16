NAME = ./gnl
SRS =	get_next_line.c \
		get_next_line_utils.c \
		main.c
HEADER = -I ./get_next_line.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

TEXT_WAR = ./war_and_piece
TEXT_SIMPLE = ./text
TEXT_NULL = ./null

compile: $(SRC)
	$(CC) $(CFLAGS) get_next_line.c get_next_line_utils.c main.c $(HEADER) -o $(NAME)
war:
	time $(NAME) $(TEXT_WAR) > out
text:
	time $(NAME) $(TEXT_WAR) > out
null:
	time $(NAME) $(TEXT_NULL) > out
fclean:
	$(RM) $(NAME) out
re: fclean compile

.PHONY: compile fclean re
