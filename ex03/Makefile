Name = bsp

SRCS = main.cpp Fixed.cpp Point.cpp bsp.cpp

HEADERS = Fixed.hpp Point.hpp

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

OBJS = $(SRCS:.cpp=.o)


all : $(Name)

$(Name) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(Name)

%.o : %.cpp $(HEADERS)
	$(CC) $(FLAGS)  $< -c -o $@

clean :
	rm -f $(OBJS)
fclean : clean
	rm -f $(Name)

re : fclean all

.PHONY : all clean fclean re

