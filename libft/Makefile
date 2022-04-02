.PHONY: all clean fclean re bonus

SRCS	=	ft_atoi.c		\
            ft_bzero.c		\
            ft_calloc.c		\
            ft_isalnum.c	\
            ft_isalpha.c	\
			ft_isascii.c	\
			ft_isdigit.c	\
			ft_isprint.c	\
			ft_memccpy.c	\
			ft_memchr.c		\
			ft_memcmp.c		\
			ft_memcpy.c		\
			ft_memmove.c	\
			ft_memset.c		\
			ft_strchr.c		\
			ft_strdup.c		\
			ft_strlen.c		\
			ft_strlcat.c	\
			ft_strlcpy.c	\
			ft_strnstr.c	\
			ft_strncmp.c	\
			ft_strrchr.c	\
			ft_tolower.c	\
			ft_toupper.c	\
			ft_substr.c		\
			ft_strjoin.c	\
			ft_strtrim.c	\
			ft_putchar_fd.c	\
			ft_putstr_fd.c	\
			ft_putendl_fd.c	\
			ft_putnbr_fd.c	\
			ft_sign.c		\
			ft_strmapi.c	\
			ft_itoa.c		\
			ft_split.c		\
			ft_lstnew.c		\
			ft_lstadd_front.c	\
			ft_lstsize.c	\
			ft_lstlast.c	\
			ft_lstadd_back.c	\
			ft_lstdelone.c	\
			ft_lstiter.c

OBJS	=	${SRCS:.c=.o}
DEPS	=	${OBJS:.o=.d}

L_HEAD	=	libft.h

NAME	=	libft.a
RM		=	rm -f
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -MMD

%.o: %.c	${L_HEAD}
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	@ar rc ${NAME} ${OBJS}
	@ranlib ${NAME}

all:		${NAME}

clean:
	@${RM} ${OBJS} ${DEPS}

fclean:		clean
	@${RM} ${NAME}

re:			clean fclean all

include $(wildcard $(DEP))
