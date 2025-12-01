CFLAGS = -Wall -Wextra -Werror
CC = cc
NAME = libftprintf.a
SRCS = ft_printf_utils.c ft_printf.c
TEST_SRC = test.c
TEST_NAME = program
INCLUDE = ft_printf.h
SILENT = @

OBJ_FILES = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@ar rcs $@ $^

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(TEST_NAME): $(NAME) $(TEST_SRC)
	@$(CC) $(CFLAGS) $(TEST_SRC) -s -L. -lftprintf -o $(TEST_NAME)


clean:
	@rm -rf $(OBJ_FILES)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(TEST_NAME)

re: fclean all

test: $(TEST_NAME)
	./$(TEST_NAME)

.PHONY: all clean fclean re test

