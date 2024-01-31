RED		:=\e[31m
GREEN	:=\e[32m
ORANGE	:=\e[33m
BLUE	:=\e[34m
PURPLE	:=\e[35m
CYAN	:=\e[36m
 
BOLD	:=\e[1m
DIM		:=\e[2m
BOM		:=\e[22m
ITALIC	:=\e[3m
NOITA	:=\e[23m
 
GOTO_B  :=\e[1A\e[K
 
DEFAULT :=\e(B\e[m

FILES		:=	main.c			\
				close.c			\
				event.c			\
				game.c			\
				menu.c			\
				collision.c		\
				tetromino.c

SRC_PATH	:=	src
SRC			:=	$(addprefix $(SRC_PATH)/,$(FILES))

OBJ_PATH	:=	build
OBJ			:=	$(addprefix $(OBJ_PATH)/,$(FILES:.c=.o))

DEPENDS		:= $(OBJ:.o=.d)

MLX_PATH	:=	mlx
MLX			:=	mlx

FT_PATH		:=	libft
FT			:=	ft

INCLUDES	:=	. include
CINC		:=	$(addprefix -I,$(INCLUDES))

CLIB		:=	-L$(MLX_PATH) -L$(FT_PATH) -l$(MLX) -l$(FT) -lXext -lX11

CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror
GDB			:=	-g3
export GDB

NAME		:= tetris

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ) $(MLX_PATH)/lib$(MLX).a $(FT_PATH)/lib$(FT).a
	@echo "$(ORANGE)Linking into $(ITALIC)$(BOLD)$@$(DEFAULT)"
	@$(CC) $(CFLAGS) $(CINC) $(GDB) -o $@ $^ $(CLIB) && echo "$(GOTO_B)$(GREEN)Successfully linked into $(ITALIC)$(BOLD)$@$(DEFAULT)"

$(MLX_PATH)/lib$(MLX).a:
	@make --silent -C $(MLX_PATH)

$(FT_PATH)/lib$(FT).a:
	@make --silent -C $(FT_PATH)

-include $(DEPENDS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	@echo "$(ORANGE)Compiling the file $(BOLD)$<$(DEFAULT)"
	@$(CC) $(CFLAGS) $(CINC) $(GDB) -MMD -MP -o $@ -c $< && echo "$(GOTO_B)$(GREEN)Successfully compiled the file $(BOLD)$<$(DEFAULT)"

$(OBJ_PATH)/%.o: %.c | $(OBJ_PATH)
	@echo "$(ORANGE)Compiling the file $(BOLD)$<$(DEFAULT)"
	@$(CC) $(CFLAGS) $(CINC) $(GDB) -MMD -MP -o $@ -c $< && echo "$(GOTO_B)$(GREEN)Successfully compiled the file $(BOLD)$<$(DEFAULT)"

$(OBJ_PATH):
	@mkdir $@ && echo "$(DIM)Created the directory $(ITALIC)$@$(DEFAULT)"

.PHONY: clean fclean re
clean:
	@(rm $(OBJ) 2> /dev/null && echo "$(RED)Removed all the object files$(DEFAULT)") ||:
	@rm -f $(DEPENDS)

fclean: clean
	@(rm $(NAME) 2> /dev/null && echo "$(RED)Removed the executable $(NAME)$(DEFAULT)") ||:
	@make --silent fclean -C $(FT_PATH)
	@make --silent clean -C $(MLX_PATH)

re: fclean all

