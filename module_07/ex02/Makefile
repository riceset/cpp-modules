NAME = array

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

PATH_SRCS = ./sources/
PATH_INCS = ./includes/
PATH_TMPT = ./templates/
PATH_OBJS = ./objects/

SRCS = 	main.cpp

OBJS = $(SRCS:.cpp=.o)
OBJS := $(addprefix $(PATH_OBJS),$(OBJS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(PATH_OBJS)%.o: $(PATH_SRCS)%.cpp
	@mkdir -p $(PATH_OBJS)
	$(CXX) $(CXXFLAGS) -I$(PATH_INCS) -I$(PATH_TMPT) -c $< -o $@

clean:
	$(RM) -r $(PATH_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run:
	@make --silent
	@./$(NAME)

.PHONY: all clean fclean re run