NAME	=	cub3d
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g
RM		=	rm -rf
SRC		=	main allocations player mlx_utils algorithm movement
SRC_DIR	=	srcs
SRCS	=	$(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC)))
OBJ_DIR	=	obj
OBJS	=	$(addprefix $(OBJ_DIR)/, $(SRC:=.o))
LIBFT_PATH	=	./libft
LIBFT		=	$(LIBFT_PATH)/libft.a
MLX_PATH	=	./minilibx-linux
MLX			=	$(MLX_PATH)/libmlx.a

LDFLAG	=	-L$(LIBFT_PATH) -L$(MLX_PATH)
all:
	$(MAKE) -C $(LIBFT_PATH) all
	$(MAKE) -C $(MLX_PATH) all
	$(MAKE) $(NAME)

$(NAME):	$(OBJS) $(LIBFT) $(MLX)
			$(CC) $(CFLAGS) $(^) -o $(@) -lreadline -lXext -lX11 -lm $(LDFLAG)

$(OBJ_DIR):
			mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
			$(CC) $(CFLAGS) -c $< -o $@

clean:
		make -C $(LIBFT_PATH) clean
		make -C $(MLX_PATH) clean
		$(RM) $(OBJS)
fclean: clean
				make -C $(LIBFT_PATH) fclean
				$(RM) $(OBJS) $(NAME)
re: fclean all

.PHONY:	all clean fclean re
