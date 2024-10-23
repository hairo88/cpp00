CC=g++
CFLAGS= -Wall -Wextra -Werror -std=c++98

TARGET=megaphone

SRC= Megaphone.cpp
OBJ= $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ) $(TARGET)

re: fclean
	all

.PHONY: all clean