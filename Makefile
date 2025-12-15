NAME := so_long

NAME_C := $(NAME).c
HDR_DIR = .

#Libs
HLP_DIR :=	helpers
HLP_ARC :=	$(HLP_DIR)/lib/lib.a	\
			$(HLP_DIR)/printf/prt.a

SRC_DIR :=	sources
SRC_ARC :=	$(SRC_DIR)/parse/parse.a	\
			$(SRC_DIR)/game/game.a		\
			$(SRC_DIR)/data/data.a		\
			$(SRC_DIR)/assets/assets.a

MLX_DIR :=	mlx
MLX_ARC :=	$(MLX_DIR)/libmlx.a

ALL_ARC := $(SRC_ARC) $(HLP_ARC) 

ALL_C := $(foreach arc, $(ALL_ARC), $(wildcard $(dir $(arc))*.c))

#Vars
MAKEFLAGS += --no-print-directory

FLAGS := -Wall -Wextra -Werror

MLX_FLAGS := -lX11 -lXext

RM := rm -f

blank :=
define NEWLINE

$(blank)
endef

COLOUR_GREEN := \033[1;32m
COLOUR_RED := \033[1;31m
COLOUR_YELLOW := \033[1;33m
COLOUR_BLUE := \033[1;34m
COLOR_WHITE := \033[0m

all: $(NAME)

$(NAME): $(MLX_ARC) $(ALL_ARC) $(NAME_C) 
	@cc $(FLAGS) -o $@ -I$(HDR_DIR)  $(NAME_C) $(ALL_ARC) $(MLX_ARC) $(MLX_FLAGS)
	@echo "$(COLOUR_GREEN)Made main file$(COLOR_WHITE)"

$(ALL_ARC): $(ALL_C)
ifeq ($($?),)
	@echo "$(COLOUR_BLUE)Updating archives of $@$(COLOR_WHITE)"
	@cd $(dir $@) && make
	@touch $@
endif

$(MLX_ARC): $(MLX_DIR)
	@echo "$(COLOUR_BLUE)Updating archives of $@$(COLOR_WHITE)"
	@cd $(dir $@) && make
	@touch $@

$(MLX_DIR):
	git clone https://github.com/42paris/minilibx-linux.git $(MLX_DIR)


clean:
	@echo "$(COLOUR_YELLOW)Cleaning archives$(COLOR_WHITE)"
	@$(foreach dir,$(dir $(ALL_ARC)), cd $(dir) && make fclean && echo$(NEWLINE)$(NEWLINE))
	@cd $(dir $(MLX_ARC)) && make clean

fclean: 
	@echo "$(COLOUR_YELLOW)Cleaning everything$(COLOR_WHITE)"
	@$(RM) $(NAME)
	@$(foreach dir,$(dir $(ALL_ARC)), cd $(dir) && make fclean && echo$(NEWLINE)$(NEWLINE))
	@echo "$(COLOUR_RED)	Cleaning Mini Libx$(COLOUR_WHITE)"
	@$(RM) -r $(MLX_DIR)


re: re_libs all

re_libs:
	@echo "$(COLOUR_BLUE)Remaking everything$(COLOR_WHITE)"
	@$(foreach dir,$(dir $(ALL_ARC)), cd $(dir) && make re && echo$(NEWLINE)$(NEWLINE))

.PHONY: all clean fclean re
