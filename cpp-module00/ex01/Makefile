NAME = Phonebook

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = phonebook.cpp \
	   prompt.cpp \
	   fillDetails.cpp \
	   add.cpp \
	   formatString.cpp \
	   getters.cpp \
	   setters.cpp

OBJS = $(SRCS:%.cpp=%.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
