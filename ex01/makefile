CC=g++
CFLAGS= -g -Wall -Wextra -Werror -std=c++98

TARGET=Phonebook

SRC= main.cpp \
	Phonebook.cpp \
	Contact.cpp
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

.PHONY: all clean