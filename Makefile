RED	= \033[0;31m
YELLOW = \033[0;33m
GREEN = \033[0;32m
MAGENTA	= \033[0;35m
RESET_COLOR = \033[0m

define ASCII_ART
		·▄▄▄·▄▄▄▄  ·▄▄▄
		▐▄▄·██▪ ██ ▐▄▄·
		██▪ ▐█· ▐█▌██▪ 
		██▌.██. ██ ██▌.
		▀▀▀ ▀▀▀▀▀• ▀▀▀ 
endef
export ASCII_ART


#*compilation
NAME = minishell

CC = gcc
DEPFLAGS = -MMD -MP
CC_FLAGS = -Wall -Wextra -Werror -g $(DEPFLAGS) 

SRC =	src/cmd/cmd_list.c\
		src/cmd/cmd.c\
		src/envp/envp.c\
		src/envp/envp_init.c\
		src/envp/envp_list.c\
		src/lexer/lexer.c\
		src/lexer/lexer_list.c\
		src/minishell_main/main.c\
		src/utils/exit.c\
		src/utils/free_utils.c\
		src/utils/free.c\
		src/utils/init_tools.c\
		src/utils/reset.c\
		src/utils/signals.c\
		src/utils/str_utils.c\
		src/utils/utils.c\
		src/utils/singlesplit.c\
		src/execute/builtin.c\
		src/execute/exec_redir.c\
		src/execute/execute.c\
		src/execute/exit_builtin.c\
		src/execute/export_utils.c\
		src/execute/export.c\
		src/execute/ft_cd.c\
		src/execute/ft_export.c\
		src/execute/ft_pwd.c\
		src/execute/ft_unset.c\
		src/execute/pipe_list.c\
		src/execute/pipe_utils.c\
		src/execute/pipe.c\
		src/execute/redir.c\
		src/execute/shlvl.c\

OBJ = $(addprefix $(OBJ_F), $(SRC:%.c=%.o))

VPATH = $(SRC_F) $(SRC_F)utils/
SRC_F = src/
OBJ_F = obj/

#*libs
LIBFT_F = libft
LIBFLAGS = -L$(LIBFT_F) -lft


#specify the name, where the archive will be downloaded from url
# MLX_ARCH = minilibx.tgz
# MLX = $(addprefix $(MLX_F)/, $(MLX_NAME))

#* OS dependent flags
# UNAME = $(shell uname -s)
# ifeq ($(UNAME), Darwin)
# 	#MacOS
# #preprocessor definition, define macros name, used in .h files depending on OS
# CC_FLAGS += -D OSX
# MLX_F = mlx-osx
# # MLX_NAME = libmlx.dylib
# MLX_URL = https://cdn.intra.42.fr/document/document/21664/minilibx_mms_20191025_beta.tgz
# MLX_LIBS = -lmlx -framework OpenGL -framework AppKit
# else
# 	#Linux
# CC_FLAGS += -D LINUX
# MLX_F = mlx-linux
# # MLX_NAME = libmlx.a
# MLX_URL = https://cdn.intra.42.fr/document/document/21665/minilibx-linux.tgz
# MLX_LIBS = -lmlx-Linux -Xext -lX11
# endif



# .SILENT:
all: $(NAME)

run: $(NAME)

$(NAME): $(OBJ)
	@echo "\n"
	$(MAKE) -C $(LIBFT_F)
	$(CC) $(LIBFLAGS) -o $@ $<
	@echo "$(MAGENTA)$$ASCII_ART$(RESET_COLOR)"
	@echo "$(GREEN)\n———————————————✣ FDF COMPILED ✣————————————\n$(RESET_COLOR)"

$(OBJ_F)%.o: %.c $(LIBFT_F)
	mkdir -p $(@D)
	$(CC) $(CC_FLAGS) -o $@ -c $<
	@printf "$(GREEN). $(RESET_COLOR)"

$(LIBFT_F):
	echo "$(GREEN)\n\nDownloading $(LIBFT_F) ...$(RESET_COLOR)"


clean:
	clear;
	$(MAKE) -C $(LIBFT_F) fclean;
	rm -rf $(OBJ_F)
	@echo "$(YELLOW)\n CLEAN FDF		🧹✨$(RESET_COLOR)"

fclean:	clean
	rm -f $(NAME)
	@echo "$(YELLOW)FCLEAN FDF		🧹✨\n$(RESET_COLOR)"

re:		fclean all

uninstall: $(LIBFT_F)
	rm -rf $(LIBFT_F)

.PHONY:	all clean fclean re maps run
