NAME 	:= libft.a

CC 		:= cc
CFLAGS 	:= -Wall -Wextra -Werror -MMD -g3
AR 		:= ar
ARFLAGS := rcs
RM 		:= rm -fr

OBJDIR 	:= obj

SRCS    :=  ft_atoi.c       ft_bzero.c     ft_calloc.c     ft_close.c      \
			ft_ctx.c        ft_free.c      ft_isalnum.c    ft_isalpha.c    \
			ft_isascii.c    ft_isdigit.c   ft_islower.c    ft_isprint.c    \
			ft_isspace.c    ft_isupper.c   ft_itoa.c       ft_itoa_str.c   \
			ft_malloc.c     ft_memchr.c    ft_memcmp.c     ft_memcpy.c     \
			ft_memmove.c    ft_memset.c    ft_ptrlist.c    ft_putchar_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c  ft_split.c      \
			ft_strchr.c     ft_strcmp.c    ft_strdup.c     ft_striteri.c   \
			ft_strjoin.c    ft_strlcat.c   ft_strlcpy.c    ft_strlen.c     \
			ft_strmapi.c    ft_strncmp.c   ft_strnstr.c    ft_strrchr.c    \
			ft_strtrim.c    ft_substr.c    ft_tolower.c    ft_toupper.c    \
			ft_exit.c       ft_panic.c     ft_open.c


OBJS 	:= $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
DEPS 	:= $(OBJS:.o=.d)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(DEPS)


