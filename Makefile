
NAME            = push_swap
BONUS			= checker
CC              = cc
CFALGS          = -O2 -Wall -Wextra -Werror
RM              = rm -rf
LIBFT_DIR       = libft/
LIBFT           = $(LIBFT_DIR)libft.a
SRC_DIR         = src/
HEADER          = ./inc/push_swap.h
HEADER_LIBFT	= ./libft/libft.h
SRC_FILES       = push_swap.c\
					free_error.c\
					lst_init_a.c\
					unique_num.c\
					stack.c\
					min_push_pb.c\
					push_a.c\
					rx_rrx.c

SRC_DIR_B       = src_bonus/
HEADER_B        = ./inc/checker_bonus.h
SRC_FILES_B     = checker_bonus.c\
					free_error_bonus.c\
					lst_init_a_bonus.c\
					stack_bonus.c\
					read_stdin_bonus.c\
					get_next_line_bonus.c

OBJS            = $(patsubst %.c, %.o, $(addprefix $(SRC_DIR), $(SRC_FILES)))
OBJS_B          = $(patsubst %.c, %.o, $(addprefix $(SRC_DIR_B), $(SRC_FILES_B)))

all:            $(LIBFT) $(NAME)
bonus:			$(LIBFT) $(BONUS)

$(NAME)			: $(OBJS) $(HEADER) $(LIBFT)
			$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $@
$(BONUS)		: $(OBJS_B) $(HEADER_B) $(LIBFT)
			$(CC) $(CFLAGS) $(OBJS_B) -L$(LIBFT_DIR) -lft -o $@

$(SRC_DIR)%.o	: $(SRC_DIR)%.c $(HEADER) $(LIBFT)
			$(CC) $(CFLAGS) -c $< -o $@
$(SRC_DIR_B)%.o	: $(SRC_DIR_B)%.c $(HEADER_B) $(LIBFT)
			$(CC) $(CFLAGS) -c $< -o $@
$(LIBFT): $(HEADER_LIBFT)
		make -C $(LIBFT_DIR)
clean:
		$(RM) $(OBJS)
		$(RM) $(OBJS_B)
		make -C $(LIBFT_DIR) clean
fclean: clean
		$(RM) $(NAME)
		$(RM) $(BONUS)
		make -C $(LIBFT_DIR) fclean
re:		fclean all
.PHONY: all clean fclean re