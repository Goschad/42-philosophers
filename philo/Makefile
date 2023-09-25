NAME = philo

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRCS =	main.c \
		utils.c \
		check.c \
		init.c \
		time.c \
		die_check.c \
		thread_start.c \
		bro_think.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@echo "philosophers cleaned"

fclean: clean
	@rm -rf $(NAME)
	@echo "philosophers fcleaned"

re: fclean all
