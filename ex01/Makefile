# == Makefile ==

NAME = bureaucrat
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -I$(INC_DIR)

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes

SRCS =	main.cpp \
		$(SRC_DIR)/Bureaucrat.cpp \

OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# == Couleurs pour les messages dans le terminal ==
YELLOW = \033[1;33m
NC = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	@echo "$(YELLOW)Object file cleaned.$(NC)"

fclean: clean
	rm -f $(NAME)
	@echo "$(YELLOW)Executable removed.$(NC)"

re: fclean all

.PHONY: all clean fclean re
