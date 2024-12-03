# Répertoires
LIBFT_DIR = libft/_libft
PRINTF_DIR = libft/ft_printf
OBJ_DIR = objects
UTILS_DIR = utils

# Fichiers sources
SRC_FILES = errors.c init_and_parse.c min_and_max.c push_swap.c radix_sort.c
UTILS_FILES = push.c reverse_rotate.c rotate.c swap.c

SRC = $(SRC_FILES) $(addprefix $(UTILS_DIR)/, $(UTILS_FILES))

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Bibliothèques et headers
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
INC = push_swap.h $(PRINTF_DIR)/ft_printf.h $(LIBFT_DIR)/libft.h

# Noms de l'executable
PUSH_SWAP = push_swap

# Règle par défaut : compiler les exécutables
all: $(OBJ_DIR) $(LIBFT) $(PRINTF) $(PUSH_SWAP)

# Créer le répertoire pour les objets (et sous-dossiers)
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)/$(UTILS_DIR)

# Créer la bibliothèque libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# Créer la bibliothèque ft_printf
$(PRINTF):
	make -C $(PRINTF_DIR)

# Créer l'executable
$(PUSH_SWAP): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) -o $(PUSH_SWAP) $(LIBFT) $(PRINTF)

# Règle pour générer les fichiers objets
$(OBJ_DIR)/%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean

# Nettoyage complet (objets + exécutables)
fclean: clean
	rm -f $(PUSH_SWAP)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

# Recompilation complète
re: fclean all

# Marque que les règles ne sont pas des fichiers
.PHONY: all clean fclean re
