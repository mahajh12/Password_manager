NAME = passmanager

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RLFLAGS = -lreadline -lncurses

RM = rm -rf

SRCS =		main.c	   \
			add_acc.c	\
			lst_utilis.c \
			lst_utilis2.c \
			show_acc.c	  \
			encryption.c  \
			parse_file.c

OBJS = $(SRCS:.c=.o)

all: $(NAME) MKDIR

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(RLFLAGS) $(OBJS) -o $(NAME) -o ${NAME}

MKDIR:
	@mkdir obj
	@mv *.o obj

clean:
	$(RM) $(OBJS)
	$(RM) obj

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME) MKDIR

.PHONY = all clean fclean re MKDIR 

all: $(NAME)