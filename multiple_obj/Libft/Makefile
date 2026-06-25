CC = cc
CFLAGS = -Wall -Wextra -Werror
CFILES = ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
              ft_split.c ft_strlen.c ft_strdup.c ft_strchr.c ft_strrchr.c \
              ft_strncmp.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
              ft_memchr.c ft_memcmp.c ft_calloc.c ft_strlcpy.c ft_strlcat.c \
              ft_toupper.c ft_tolower.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
              ft_isascii.c ft_isprint.c ft_atoi.c ft_substr.c ft_strjoin.c \
              ft_strtrim.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_strnstr.c \
			  get_next_line.c get_next_line_utils.c

OFILES = $(CFILES:.c=.o)
NAME = libft.a

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $@ $(OFILES) libft.h

%.o: %.c
	$(CC) -c -Iinclude $(CFLAGS) -o $@ $^

clean:
	rm -f prog *.o

fclean: clean
	rm -f $(NAME)

save:	$(NAME) clean
	git status
	git add *
	git commit -a -m "auto-save"
	git push git@github.com:ThomPrs/Libft.git

re: fclean $(NAME)
